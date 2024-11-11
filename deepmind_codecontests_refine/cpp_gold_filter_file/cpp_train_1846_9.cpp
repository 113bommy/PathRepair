#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  int n, m, t, k;
  cin >> k;
  vector<int> lens(k);
  vector<int> sums(k);
  vector<int> seqs[k];
  for (int i = 0; i < k; i++) {
    cin >> lens[i];
    seqs[i].resize(lens[i]);
    for (int j = 0; j < lens[i]; j++) {
      cin >> seqs[i][j];
      sums[i] += seqs[i][j];
    }
  }
  set<pair<int, int>> s;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < seqs[i].size(); j++) {
      s.insert(make_pair(sums[i] - seqs[i][j], i));
    }
  }
  bool res = false;
  auto prev = s.begin();
  int idC1, idEl1, idC2, idEl2;
  auto el = prev;
  while ((++el) != s.end()) {
    if (el->first == prev->first && el->second != prev->second) {
      res = true;
      idC1 = el->second;
      idC2 = prev->second;
      int elementToFind = sums[el->second] - el->first;
      for (int i = 0; i < seqs[idC1].size(); i++) {
        if (seqs[idC1][i] == elementToFind) {
          idEl1 = i;
          break;
        }
      }
      elementToFind = sums[prev->second] - prev->first;
      for (int i = 0; i < seqs[idC2].size(); i++) {
        if (seqs[idC2][i] == elementToFind) {
          idEl2 = i;
          break;
        }
      }
      break;
    }
    prev = el;
  }
  if (res) {
    cout << "YES" << endl;
    cout << idC1 + 1 << " " << idEl1 + 1 << endl;
    cout << idC2 + 1 << " " << idEl2 + 1 << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
