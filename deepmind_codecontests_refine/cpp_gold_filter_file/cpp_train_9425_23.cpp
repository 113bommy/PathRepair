#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXABSK = 1e4 + 4;
const int UNKNOWN = 0x3f3f3f3f;
int N, K;
string A[MAXN];
int coef[MAXN];
int qcnt;
bool humanLast(int n, int q) { return ((n - q) & 1) ^ !(q & 1); }
bool divisible(int i, int s) {
  if (i == N + 1) return s == 0;
  s += coef[i];
  if (s % K != 0) return false;
  return divisible(i + 1, s / K);
}
void solve() {
  memset(coef, UNKNOWN, sizeof(coef));
  for (int i = 0; i < N + 1; ++i) {
    if (A[i] != "?")
      coef[i] = atoi(A[i].c_str());
    else
      ++qcnt;
  }
  if (K == 0) {
    if (coef[0] == 0)
      puts("Yes");
    else if (coef[0] == UNKNOWN)
      puts(((N + 1 - qcnt) & 1) ? "Yes" : "No");
    else
      puts("No");
  } else {
    if (qcnt > 0)
      puts(humanLast(N + 1, qcnt) ? "Yes" : "No");
    else
      puts(divisible(0, 0) ? "Yes" : "No");
  }
}
int main() {
  cin >> N >> K;
  for (int i = 0; i < N + 1; ++i) cin >> A[i];
  solve();
  return 0;
}
