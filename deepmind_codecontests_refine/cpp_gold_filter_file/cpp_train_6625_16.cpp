#include <bits/stdc++.h>
using namespace std;
vector<int> ind[26];
int binS(int i, int cur) {
  int mi = -1, ma = ind[i].size() - 1;
  while (mi + 1 < ma) {
    int mid = (mi + ma) / 2;
    if (ind[i][mid] > cur)
      ma = mid;
    else
      mi = mid;
  }
  return ind[i][ma];
}
int main() {
  int ans = 0;
  string s1, s2;
  cin >> s1 >> s2;
  int cur = -1;
  for (int i = 0; i < (s1.size()); i++) ind[int(s1[i]) - 97].push_back(i);
  for (int i = 0; i < int(s2.size()); i++) {
    if (ind[int(s2[i]) - 97].empty()) {
      cout << -1 << endl;
      return 0;
    }
    if (cur >= ind[int(s2[i]) - 97][int(ind[int(s2[i]) - 97].size()) - 1]) {
      ans++;
      cur = -1;
    }
    cur = binS(int(s2[i]) - 97, cur);
  }
  cout << ans + 1 << endl;
  return 0;
}
