#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 7;
long long res, n, m, cnt, ans, a, b, sum, mx, mn = 1e9, c, d;
long long used[N];
vector<int> v;
map<long long, long long> mp;
string s, s1;
int main() {
  long long T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    long long arr[n + 1];
    long long d[m * 2 + 2];
    pair<int, int> p[m * 2 + 1];
    for (int i = 1; i <= m * 2; i++) {
      d[i] = 0;
      p[i].first = p[i].second = 0;
    }
    mx = ans = 0;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n / 2; i++) {
      p[i] = {arr[n - i + 1], arr[i]};
    }
    d[1] = 2 * (n / 2);
    for (int i = 1; i <= n / 2; i++) {
      a = min(1 + p[i].first, p[i].second + 1);
      b = max(m + p[i].first, p[i].second + m);
      d[a] -= 1, d[b + 1] += 1;
      d[m * 2 + 1] -= 2;
      d[p[i].first + p[i].second] -= 1, d[p[i].first + p[i].second + 1] += 1;
    }
    cnt = d[1], mx = d[1];
    for (int i = 2; i <= m * 2; i++) cnt += d[i], mx = min(cnt, mx);
    cout << mx << endl;
  }
}
