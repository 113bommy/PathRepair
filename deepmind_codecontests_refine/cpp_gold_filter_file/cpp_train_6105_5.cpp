#include <bits/stdc++.h>
using namespace std;
int N, M;
int dn[101][101][26];
char ch[101][101];
int f(int a, int b, int k) {
  if (dn[a][b][k]) return dn[a][b][k];
  int rv = -1, child;
  for (int i = 1; i <= N; i++)
    if (ch[a][i] - 'a' >= k) {
      child = f(b, i, ch[a][i] - 'a');
      if (child == -1) {
        rv = 1;
        break;
      }
    }
  return dn[a][b][k] = rv;
}
int main() {
  cin >> N >> M;
  int a, b;
  char c;
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    ch[a][b] = c;
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) cout << (f(i, j, 0) == 1 ? 'A' : 'B');
    cout << endl;
  }
  return 0;
}
