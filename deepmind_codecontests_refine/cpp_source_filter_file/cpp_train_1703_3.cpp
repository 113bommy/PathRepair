#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-11;
const int INF = 1 << 30;
const int dx[] = {
    1,
    0,
    -1,
    0,
};
const int dy[] = {
    0,
    1,
    0,
    -1,
};
int main() {
  int n, i, j, k, cnt = 0, m, M;
  char cmp[] = "AB";
  string s;
  cin >> n >> k >> s;
  if (k == 2) {
    M = m = 0;
    for (i = 0; i < n; i++)
      if (s[i] == cmp[i % 2]) m++;
    M = m;
    m = 0;
    for (i = 0; i < n; i++)
      if (s[i] == cmp[(i + 1) % 2]) m++;
    if (m < M) {
      M = m;
      cout << M << endl;
      for (i = 0; i < n; i++) cout << cmp[(i + 1) % 2];
      cout << endl;
    } else {
      cout << M << endl;
      for (i = 0; i < n; i++) cout << cmp[i % 2];
      cout << endl;
    }
    return 0;
  }
  for (i = 1; i < n - 1; i++) {
    if (s[i] == s[i - 1]) {
      for (j = 0; j < k; j++)
        if (s[i - 1] != ('A' + j) && s[i + 1] != ('A' + j)) break;
      s[i] = 'A' + j;
      cnt++;
    }
  }
  if (s[n - 2] == s[n - 1]) {
    if (s[i] == 'A')
      s[i] = 'B';
    else
      s[i] = 'A';
    cnt++;
  }
  cout << cnt << endl << s << endl;
  return 0;
}
