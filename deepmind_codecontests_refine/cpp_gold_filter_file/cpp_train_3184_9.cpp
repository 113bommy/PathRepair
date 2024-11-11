#include <bits/stdc++.h>
using namespace std;
signed long long S, F, T;
int N;
signed long long A[101010], B[101010];
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> S >> F >> T >> N;
  signed long long p = S;
  for (i = 0; i < (N); i++) {
    cin >> A[i];
    B[i] = max(p, A[i]);
    p = B[i] + T;
  }
  if (A[0] > S) {
    cout << S << endl;
  } else if (B[N - 1] + 2 * T <= F) {
    cout << F - T << endl;
  } else {
    signed long long ret = A[0] - 1, hoge = S - ret;
    for (i = 0; i < (N - 1); i++) {
      signed long long c = A[i + 1] - 1;
      signed long long w = B[i] + T - c;
      if (w < hoge && B[i] + 2 * T <= F) ret = c, hoge = w;
    }
    cout << ret << endl;
  }
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  solve();
  return 0;
}
