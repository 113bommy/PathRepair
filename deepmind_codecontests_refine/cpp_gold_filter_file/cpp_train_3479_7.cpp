#include <bits/stdc++.h>
using namespace std;
int main() {
  int m;
  cin >> m;
  vector<int> seq1;
  vector<int> seq2;
  seq1.clear();
  seq2.clear();
  map<int, int> M;
  M.clear();
  int sup = 0;
  for (int i = 0; i < m; i++) {
    int tmp;
    cin >> tmp;
    M[tmp]++;
    sup = max(tmp, sup);
    if (M[tmp] == 1) {
      seq1.push_back(tmp);
    }
    if (M[tmp] == 2) {
      seq2.push_back(tmp);
    }
  }
  sort(seq1.begin(), seq1.end());
  sort(seq2.begin(), seq2.end());
  long long out = seq1.size() + seq2.size();
  int h = seq2.size() - 1;
  if (h >= 0)
    while (seq2[h] == sup) {
      out--;
      h--;
      if (h == -1) break;
    }
  cout << out << endl;
  for (int i = 0; i < seq1.size(); i++) {
    cout << seq1[i] << " ";
  }
  for (int i = seq2.size() - 1; i >= 0; i--) {
    if (seq2[i] != sup) cout << seq2[i] << " ";
  }
  return 0;
}
