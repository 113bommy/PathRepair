#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  vector<int> f, s;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    f.push_back(x);
  }
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    s.push_back(x);
  }
  int p1 = 0, p2 = 0;
  int s1 = f[0], s2 = s[0];
  int files;
  while (p1 < n && p2 < m) {
    if (s1 > s2) {
      ++p2;
      s2 += s[p2];
      continue;
    }
    if (s1 < s2) {
      ++p1;
      s1 += f[p1];
      continue;
    }
    if (s1 == s2) {
      ++p1;
      ++p2;
      s1 = f[p1];
      s2 = s[p2];
      files++;
    }
  }
  cout << files;
  return 0;
}
