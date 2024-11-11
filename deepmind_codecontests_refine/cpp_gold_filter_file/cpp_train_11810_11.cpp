#include <bits/stdc++.h>
using namespace std;
void _fill_int(int* p, int val, int rep) {
  int i;
  for (i = 0; i < rep; i++) p[i] = val;
}
signed long long GETi() {
  signed long long i;
  scanf("%lld", &i);
  return i;
}
int N, K;
int A[3000];
signed long long mo = 1000000007;
signed long long dpdp[2001][1 << 12];
int next[1 << 12][2];
void solve() {
  int f, i, j, k, l, x, y;
  cin >> N >> K;
  K--;
  for (i = 0; i < N; i++) cin >> A[i], A[i] /= 2;
  signed long long ret = 0;
  dpdp[0][0] = 1;
  for (i = 0; i < N; i++) {
    if (A[i] == 0) ret = ret * 2 % mo;
    for (int mask = 0; mask < 1 << K; mask++) {
      if (A[i] == 1 || A[i] == 0) {
        if (mask + 1 >= 1 << K)
          ret += dpdp[i][mask];
        else
          dpdp[i + 1][mask + 1] = (dpdp[i + 1][mask + 1] + dpdp[i][mask]) % mo;
      }
      if (A[i] == 2 || A[i] == 0) {
        if (mask & 1) {
          dpdp[i + 1][2] += dpdp[i][mask];
        } else {
          if (mask + 2 >= 1 << K)
            ret += dpdp[i][mask];
          else
            dpdp[i + 1][mask + 2] =
                (dpdp[i + 1][mask + 2] + dpdp[i][mask]) % mo;
        }
      }
    }
  }
  cout << ret % mo << endl;
}
int main(int argc, char** argv) {
  string s;
  if (argc == 1) ios::sync_with_stdio(false);
  for (int i = 1; i < argc; i++) s += argv[i], s += '\n';
  for (int i = s.size() - 1; i >= 0; i--) ungetc(s[i], stdin);
  solve();
  return 0;
}
