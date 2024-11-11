#include <bits/stdc++.h>
using namespace std;
const char *fin = "";
const char *fon = "";
const int OO = (int)(1e9 + 7);
const int MAXN = (int)(1e3 + 3);
const int MAXB = (int)(1e4 + 5);
long long f[MAXB];
long long maxE[MAXB];
long long w, b, x;
int c[MAXN];
int cost[MAXN];
int n;
int s;
void Sol() {
  f[0] = w;
  maxE[0] = w;
  for (int i = 1; i <= s; ++i) {
    f[i] = -1;
    maxE[i] = maxE[i - 1] + b;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= s; ++j)
      if (f[j] != -1) f[j] = min(f[j] + x, maxE[j]);
    for (int j = s; j >= 1; --j) {
      for (int k = 1; k <= c[i]; ++k) {
        if (j - k < 0) break;
        if (f[j - k] >= k * cost[i])
          f[j] = min(maxE[j], max(f[j], f[j - k] - 1LL * k * cost[i]));
      }
    }
  }
  for (int i = s; i > 0; --i)
    if (f[i] != -1) {
      cout << i << '\n';
      return;
    }
}
void Inp() {
  cin >> n >> w >> b >> x;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
    s += c[i];
  }
  for (int i = 1; i <= n; ++i) cin >> cost[i];
  Sol();
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Inp();
  return 0;
}
