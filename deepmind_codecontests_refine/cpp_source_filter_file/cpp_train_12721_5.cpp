#include <bits/stdc++.h>
using namespace std;
bool postoji(set<int> s, long long x) {
  long long duzina = s.size();
  s.insert(x);
  if (duzina != s.size()) return false;
  return true;
}
int main() {
  long long k = 1;
  vector<bool> gnum(20001, false);
  vector<int> tri;
  set<int> stepeni_trice[20001];
  gnum[0] = true;
  for (int i = 0; i < 20; i++) {
    if (k > 20000) break;
    gnum[k] = true;
    stepeni_trice[k].insert(i);
    tri.push_back(k);
    k *= 3;
  }
  for (int i = 0; i < 20001; i++) {
    if (gnum[i]) {
      for (int j = 0; j < 20; j++) {
        long long curr = i + tri[j];
        if (curr > 20000) break;
        if (!postoji(stepeni_trice[i], j)) {
          gnum[curr] = true;
          stepeni_trice[curr].insert(j);
        }
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    for (int i = n + 1; i < 20001; i++) {
      if (gnum[i]) {
        cout << i << endl;
        break;
      }
    }
  }
  return 0;
}
