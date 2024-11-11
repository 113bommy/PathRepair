#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T& x) {
  x = 0;
  bool f = 0;
  char ch = (char)getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = 1;
    ch = (char)getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch & 15);
    ch = (char)getchar();
  }
  if (f) x = -x;
}
template <typename T>
inline void write(T x) {
  if (x < 0) x = -x, putchar('-');
  static int st[45];
  int top = 0;
  do {
    st[top++] = x % 10;
    x /= 10;
  } while (x);
  while (top) putchar(st[--top] + '0');
  puts("");
}
const double pi = acos(-1.0);
const double eps = (double)1e-4;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxm = (1 << 22);
int n;
int arr[maxn];
int dp[maxm];
int INF = (1 << 22) - 1;
int inv(int x) { return (~x) & INF; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  fill(dp, dp + maxm, -1);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i], dp[inv(arr[i])] = arr[i];
  for (int mask = 4e6; mask >= 1; mask--) {
    if (dp[mask] != -1) continue;
    for (int j = 0; j < 22; j++) {
      int a = mask | (1 << j);
      if (a == mask) continue;
      if (dp[a] != -1) {
        dp[mask] = dp[a];
        break;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int a = arr[i];
    cout << dp[a] << " ";
  }
  cout << endl;
}
