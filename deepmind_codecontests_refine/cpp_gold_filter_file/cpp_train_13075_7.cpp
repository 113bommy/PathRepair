#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  int res = n;
  int k = 0;
  for (int i = 0; i <= m - n; i++) {
    int kol = 0;
    for (int j = 0; j < n; j++) {
      if (s[j] != t[i + j]) kol++;
    }
    if (kol < res) k = i;
    res = min(res, kol);
  }
  cout << res << endl;
  for (int j = 0; j < n; j++) {
    if (s[j] != t[k + j]) cout << j + 1 << " ";
  }
  return 0;
}
