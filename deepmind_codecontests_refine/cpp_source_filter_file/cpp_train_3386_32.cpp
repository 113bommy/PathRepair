#include <bits/stdc++.h>
using namespace std;
inline int min(int a, int b) { return (a > b) ? b : a; }
inline int max(int a, int b) { return (a > b) ? a : b; }
const int N = 2e5 + 10;
const int inf = 1e9 + 7;
const long long linf = 1e18 + 7;
int n;
long long s[N], p[N], a[N], b[N], ans;
vector<int> q;
long long f(int i, long long x) { return x * i - p[i]; }
long long f2(int i, long long x) { return x * i - p[i - 1]; }
bool nona(int i, int j, int k) {
  return (-p[k] + p[i]) * (i - j) <= (-p[j] + p[i]) * (i - k);
}
bool nona2(int i, int j, int k) {
  return (-p[k - 1] + p[i - 1]) * (i - j) <= (-p[j - 1] + p[i - 1]) * (i - k);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i] * i;
    p[i] = p[i - 1] + a[i];
  }
  ans = s[n];
  q.push_back(0);
  for (int i = 1; i <= n; i++) {
    int l = -1, r = (int)q.size() - 1;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (f(q[m], a[i]) <= f(q[m + 1], a[i]))
        l = m;
      else
        r = m;
    }
    ans = max(ans, f(q[r], a[i]) + s[n] + p[i - 1] - a[i] * (i - 1));
    while ((int)q.size() > 1 && nona(q[(int)q.size() - 2], q.back(), i))
      q.pop_back();
    q.push_back(i);
  }
  int k2[n + 3], cnt = n + 1;
  k2[n + 1] = n + 1;
  for (int i = n; i >= 1; i--) {
    int l = cnt - 1, r = n + 1;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (f2(k2[m], a[i]) <= f2(k2[m + 1], a[i]))
        l = m;
      else
        r = m;
    }
    ans = max(ans, f2(k2[r], a[i]) + s[n] + p[i] - a[i] * (i + 1));
    while (cnt <= n && nona2(k2[cnt + 1], k2[cnt], i)) cnt++;
    k2[--cnt] = i;
  }
  cout << ans << endl;
}
