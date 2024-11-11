#include <bits/stdc++.h>
using namespace std;
long long n, r, k, i, x, Sum[500005], S[500005], rez;
long long B[500005];
bool check(long long x) {
  memset(B, 0, sizeof(B));
  long long add = 0;
  long long ck = k;
  for (int i = 1; i <= n; i++) {
    add += B[i];
    if (add + S[i] < x) {
      long long val = x - (S[i] + add);
      add += val;
      ck -= val;
      B[min(i + 2 * r + 1, n + 1)] -= val;
      if (ck < 0) return 0;
    }
  }
  return (ck >= 0);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> r >> k;
  for (i = 1; i <= n; i++) {
    cin >> x;
    Sum[i] = Sum[i - 1] + x;
  }
  for (i = 1; i <= n; i++) S[i] = Sum[min(i + r, n)] - Sum[max(i - r - 1, 0LL)];
  rez = 0;
  for (i = 62; i >= 0; i--) {
    if (check(rez + (1LL << i))) rez = rez + (1LL << i);
  }
  cout << rez << "\n";
  return 0;
}
