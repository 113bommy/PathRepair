#include <bits/stdc++.h>
using namespace std;
char a[102], b[102];
int Q, n;
int T[27];
int c[102][102];
bool checkt() {
  bool OK = 0;
  for (int i = 0; i < 26; ++i) {
    if (T[i] != 0) OK = 1;
    T[i] = 0;
  }
  return OK;
}
int main() {
  for (cin >> Q; Q > 0; --Q) {
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) {
      ++T[a[i] - 'a'];
      --T[b[i] - 'a'];
    }
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= n; ++j) c[i][j] = 0;
    if (checkt()) {
      cout << "-1\n";
      continue;
    }
    int M = 0;
    for (int i = n - 1; i >= 0; --i)
      for (int j = n - 1; j >= 0; --j) {
        c[i][j] = max(c[i + 1][j], (c[i + 1][j + 1] + 1) * int(a[i] == b[j]));
        M = max(M, c[i][j]);
      }
    cout << n - M << '\n';
  }
}
