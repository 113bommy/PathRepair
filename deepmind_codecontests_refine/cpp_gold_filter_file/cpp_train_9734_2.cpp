#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
int add(int a, int b) { return a + b >= Mod ? a + b - Mod : a + b; }
int dec(int a, int b) { return a - b < 0 ? a - b + Mod : a - b; }
int mul(int a, int b) { return 1ll * a * b % Mod; }
void Add(int &a, int b) { a = add(a, b); }
void Mul(int &a, int b) { a = mul(a, b); }
void Dec(int &a, int b) { a = dec(a, b); }
int fx(long long a) {
  if (a >= Mod) a %= Mod;
  return a;
}
int C2(int a) { return fx((long long)a * (a - 1) >> 1); }
const int N = 4e3 + 50;
struct num {
  vector<int> a;
  bool zero() { return a.empty(); }
  void input() {
    static char str[N];
    scanf("%s", str + 1);
    int len = strlen(str + 1);
    for (int i = 1; i <= len; i++) a.push_back(str[len - i + 1] - '0');
  }
  int operator%(const int &p) {
    long long now = 0;
    for (int i = a.size() - 1; ~i; i--) {
      now = (now * 10ll + a[i]) % p;
    }
    return now;
  }
  num operator/(const int &p) {
    long long now = 0;
    num b;
    for (int i = a.size() - 1; ~i; i--) {
      now = now * 10ll + a[i];
      b.a.push_back(now / p);
      now %= p;
    }
    reverse(b.a.begin(), b.a.end());
    while (!b.a.empty() && b.a.back() == 0) b.a.pop_back();
    return b;
  }
};
int p, A, n, a[N];
char S[N];
int dp[2][N][2][2];
int main() {
  scanf("%d%d", &p, &A);
  num t;
  t.input();
  while (!t.zero()) a[++n] = t % p, t = t / p;
  if (A > n) return puts("0"), 0;
  int now = 0, nxt = 1;
  dp[now][0][1][0] = 1;
  for (int i = n, c1, c2, c3, c4, c5, c6; i >= 1; i--) {
    memset(dp[nxt], 0, sizeof(dp[nxt]));
    c1 = C2(p + 1);
    c2 = C2(a[i] + 1);
    c3 = C2(p);
    c4 = fx((long long)a[i] * (p + p - 1 - a[i]) / 2);
    c5 = C2(a[i]);
    c6 = fx((long long)a[i] * (p + p + 1 - a[i]) / 2);
    for (int j = 0; j <= n - i; j++) {
      Add(dp[nxt][j][0][0],
          add(mul(c1, dp[now][j][0][0]), mul(c2, dp[now][j][1][0])));
      Add(dp[nxt][j][0][0],
          add(mul(c3, dp[now][j][0][1]), mul(c4, dp[now][j][1][1])));
      Add(dp[nxt][j][1][0], add(mul(a[i] + 1, dp[now][j][1][0]),
                                mul(p - a[i] - 1, dp[now][j][1][1])));
      Add(dp[nxt][j + 1][0][1],
          add(mul(c3, dp[now][j][0][0]), mul(c5, dp[now][j][1][0])));
      Add(dp[nxt][j + 1][0][1],
          add(mul(c1, dp[now][j][0][1]), mul(c6, dp[now][j][1][1])));
      Add(dp[nxt][j + 1][1][1],
          add(mul(a[i], dp[now][j][1][0]), mul(p - a[i], dp[now][j][1][1])));
    }
    swap(now, nxt);
  }
  int as = 0;
  for (int j = A; j <= n; j++) Add(as, add(dp[now][j][0][0], dp[now][j][1][0]));
  cout << as;
  return 0;
}
