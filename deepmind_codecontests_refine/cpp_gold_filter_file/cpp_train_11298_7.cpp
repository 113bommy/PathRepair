#include <bits/stdc++.h>
using namespace std;
char N[110][12], s[12];
int n, i, r, m, w, C, R[110], W[110], M[110];
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> N[i] >> s;
    if (s[0] == 'r')
      R[++r] = i;
    else if (s[0] == 'm')
      M[++m] = i;
    else if (s[1] == 'a')
      C = i;
    else
      W[++w] = i;
  }
  for (i = 1; i <= r; i++) cout << N[R[i]] << '\n';
  for (i = 1; i <= w; i++) cout << N[W[i]] << '\n';
  for (i = 1; i <= m; i++) cout << N[M[i]] << '\n';
  cout << N[C];
  return 0;
}
