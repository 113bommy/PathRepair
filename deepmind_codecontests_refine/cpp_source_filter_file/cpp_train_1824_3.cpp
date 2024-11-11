#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
const int P = 1000000007;
const int Inv2 = 500000004;
long long R() {
  long long ans = 0, f = 1;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) ans = ans * 10 + c - '0';
  return ans * f;
}
struct Pt {
  long long x, y;
  long long friend operator*(Pt A, Pt B) { return -A.x * B.y + A.y * B.x; }
  Pt friend operator+(Pt A, Pt B) {
    return (Pt){(A.x + B.x) % P, (A.y + B.y) % P};
  }
  Pt friend operator-(Pt A, Pt B) {
    return (Pt){(A.x - B.x) % P, (A.y - B.y) % P};
  }
} p[N], sp[N];
int n;
long long s[N], ss[N], ans;
unsigned long long All, U;
int main() {
  n = R();
  for (int i = 1; i <= n; ++i) p[i].x = R(), p[i].y = R();
  for (int i = 1; i <= n + 1; ++i) p[i + n] = p[i];
  for (int i = 1; i <= n + n; ++i) s[i] = (s[i - 1] + p[i] * p[i + 1]) % P;
  for (int i = 1; i <= n + n; ++i) ss[i] = (ss[i - 1] + s[i]) % P;
  for (int i = 1; i <= n + n; ++i) sp[i] = p[i] + sp[i - 1];
  for (int i = 1; i <= n; ++i) All += p[i] * p[i + 1];
  int rr = 1;
  for (int i = 1; i <= n; ++i) {
    while (U + p[rr] * p[rr + 1] + p[rr + 1] * p[i] <= All / 2) {
      U += p[rr] * p[rr + 1];
      ++rr;
    }
    ans += (All * (rr - i - 1)) % P;
    ans -= ((sp[rr] - sp[i + 1]) * p[i]) % P * 2;
    ans -= (ss[rr - 1] - ss[i] - (rr - i - 1) * s[i - 1]) * 2;
    ans %= P;
    U -= p[i] * p[i + 1];
  }
  ans += P;
  ans %= P;
  cout << ans << '\n';
  return 0;
}
