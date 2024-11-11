#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long int poww(long long int b, long long int e) {
  if (e == 0)
    return 1;
  else if (e % 2 == 0) {
    long long int a = pow(b, e / 2);
    return a * a;
  } else {
    long long int a = pow(b, e / 2);
    return b * a * a;
  }
}
long long int powm(long long int x, long long int y,
                   long long int m = 1000000007) {
  x = x % m;
  long long int res = 1;
  while (y) {
    if (y & 1) res = res * x;
    res %= m;
    y = y >> 1;
    x = x * x;
    x %= m;
  }
  return res;
}
long long int modInverse(long long int a, long long int m = 1000000007) {
  return powm(a, m - 2, m);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (long long int i = (0); i <= (n - 1); i += (1)) cin >> a[i];
  ;
  vector<long long int> dp1(n), dp2(n);
  dp1[0] = a[0];
  stack<long long int> s;
  s.push(0);
  for (long long int i = (1); i <= (n - 1); i += (1)) {
    while ((!s.empty()) && (a[s.top()] >= a[i])) s.pop();
    if (s.empty())
      dp1[i] = (i + 1) * a[i];
    else
      dp1[i] = dp1[s.top()] + (i - s.top()) * a[i];
    s.push(i);
  }
  while (!s.empty()) s.pop();
  dp2[n - 1] = a[n - 1];
  s.push(n - 1);
  for (long long int i = (n - 2); i >= (0); i -= (1)) {
    while ((!s.empty()) && (a[s.top()] >= a[i])) s.pop();
    if (s.empty())
      dp2[i] = (n - i) * a[i];
    else
      dp2[i] = dp2[s.top()] + (-i + s.top()) * a[i];
    s.push(i);
  }
  long long int mx = 0, pt = 0;
  for (long long int i = (0); i <= (n - 1); i += (1)) {
    if (dp1[i] + dp2[i] - a[i] > mx) {
      mx = dp1[i] + dp2[i] - a[i];
      pt = i;
    }
  }
  vector<long long int> ans;
  long long int mn = a[pt];
  for (long long int i = (pt); i >= (0); i -= (1)) {
    mn = min(mn, a[i]);
    ans.push_back(mn);
  }
  reverse(ans.begin(), ans.end());
  mn = a[pt];
  for (long long int i = (pt + 1); i <= (n - 1); i += (1)) {
    mn = min(mn, a[i]);
    ans.push_back(mn);
  }
  for (long long int i = 0; i < n; i++) cout << ans[i] << " ";
  ;
  return 0;
}
