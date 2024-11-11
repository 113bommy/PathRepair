#include <bits/stdc++.h>
using namespace std;
void setup() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(15);
}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
int n;
const int N = 4 * int(1e5);
int ST[N], A[N];
void build(int id = 1, int l = 0, int r = n - 1) {
  if (l == r) {
    ST[id] = l;
    return;
  }
  int mid = l + (r - l) / 2;
  build(2 * id, l, mid);
  build(2 * id + 1, mid + 1, r);
  ST[id] = A[ST[2 * id]] > A[ST[2 * id + 1]] ? ST[2 * id] : ST[2 * id + 1];
}
int maxi(int x, int y, int id = 1, int l = 0, int r = n - 1) {
  if (l > y or r < x) return n;
  if (l >= x and r <= y) return ST[id];
  int mid = l + (r - l) / 2;
  int LC = maxi(x, y, 2 * id, l, mid);
  int RC = maxi(x, y, 2 * id + 1, mid + 1, r);
  return A[LC] > A[RC] ? LC : RC;
}
int dp[100005];
int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) cin >> A[i], A[i]--;
  A[n - 1] = n - 1;
  A[n] = INT_MIN;
  build();
  long long ans = 0;
  dp[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--) {
    int m = maxi(i + 1, A[i]);
    dp[i] = dp[m] + n - i - 1 - (A[i] - m);
    ans += dp[i];
  }
  cout << ans << '\n';
  return 0;
}
