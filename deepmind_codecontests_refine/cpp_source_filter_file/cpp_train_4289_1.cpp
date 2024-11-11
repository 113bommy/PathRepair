#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, mod = 1e9 + 7;
vector<int> v;
long long fac[N];
int n, k;
bool check(int x) {
  while (x) {
    int y = x % 10;
    x /= 10;
    if (y != 4 && y != 7) return 0;
  }
  return 1;
}
vector<int> get(int cnt, int num) {
  set<int> s;
  vector<int> ret;
  for (int i = 1; i <= cnt; i++) s.insert(i);
  int now = 1;
  for (int i = 1; i <= cnt; i++) {
    for (int x : s) {
      if (now + fac[cnt - i] > k) {
        ret.push_back(x);
        s.erase(x);
        break;
      }
      now += fac[cnt - i];
    }
  }
  return ret;
}
void go(long long x) {
  if (x > mod) return;
  v.push_back(x);
  x *= 10;
  go(x + 7);
  go(x + 4);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  fac[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = 1ll * fac[i - 1] * i;
    if (fac[i] > mod) break;
  }
  go(4);
  go(7);
  sort(v.begin(), v.end());
  cin >> n >> k;
  long long nw = 1;
  int cnt;
  for (int i = 1; i <= n; i++) {
    nw *= i;
    cnt = i;
    if (nw >= k) break;
  }
  if (nw < k) return cout << -1, 0;
  int x = n - cnt;
  int ret = upper_bound(v.begin(), v.end(), x) - v.begin();
  vector<int> vec = get(cnt, k);
  for (int i = x + 1; i <= n; i++) {
    if (check(i) && check(vec[i - x - 1])) ret++;
  }
  cout << ret;
  return 0;
}
