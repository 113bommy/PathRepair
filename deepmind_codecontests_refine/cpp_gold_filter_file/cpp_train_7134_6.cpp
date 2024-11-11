#include <bits/stdc++.h>
using namespace std;
int n;
long long dp[200005], a[200005], s[200005], t[200005], ans = 0;
vector<long long> sl, in;
long double x_intersect(int id1, int id2) {
  return ((long double)(in[id2] - in[id1])) / (sl[id1] - sl[id2]);
}
void add(long long slope, long long inter) {
  sl.push_back(slope);
  in.push_back(inter);
  while (sl.size() >= 3) {
    if (x_intersect(sl.size() - 1, sl.size() - 3) >=
        x_intersect(sl.size() - 3, sl.size() - 2)) {
      sl.erase(sl.end() - 2);
      in.erase(in.end() - 2);
    } else
      break;
  }
}
long long f(int id, long long x) { return sl[id] * x + in[id]; }
long long query(long long x) {
  int l = 0, r = sl.size() - 1;
  while (r - l >= 3) {
    int m1 = l + (r - l) / 3;
    int m2 = r - (r - l) / 3;
    long long f1 = f(m1, x);
    long long f2 = f(m2, x);
    if (f1 < f2)
      l = m1;
    else
      r = m2;
  }
  long long ans = LLONG_MIN;
  for (int i = l; i <= r; i++) ans = max(ans, f(i, x));
  return ans;
}
void pre() {
  sl.push_back(0);
  in.push_back(0);
  for (int i = 1; i <= n; i++) {
    dp[i] = query(s[i]) + t[i];
    long long temp = i;
    add(-1ll * temp, -t[temp] + temp * s[temp]);
    ans = max(ans, dp[i]);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    s[i] = a[i];
    s[i] += s[i - 1];
    t[i] = i * a[i];
    t[i] += t[i - 1];
  }
  pre();
  cout << ans << endl;
}
