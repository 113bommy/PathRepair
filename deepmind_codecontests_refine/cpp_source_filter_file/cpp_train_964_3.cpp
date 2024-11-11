#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using dl = double;
using ull = unsigned long long;
const int N = 2e5 + 10;
ll aarray[N];
ll magic[505][505];
vector<ll> primes;
bool ok[1000001];
map<ll, ll> mp;
void solve() {
  ll i, n, k, ans = 0, w = 0, j;
  string str;
  cin >> n >> k;
  cin >> str;
  for (i = 0; i < str.length(); i++) {
    if (str[i] == 'W') w++;
  }
  if (w + k >= n) {
    cout << 2 * n - 1 << "\n";
    return;
  }
  ll pre[100000 + 10];
  memset(pre, 0, sizeof(pre));
  for (i = 1; i < str.length() - 1; i++) {
    if (str[i] == 'L' && str[i - 1] == 'W' && str[i + 1] == 'W' && k)
      str[i] = 'W', k--;
  }
  for (i = str.length() - 1; i >= 0; i--) {
    if (str[i] == 'W') {
      pre[i] = i;
    } else {
      if (i == str.length() - 1) {
        pre[i] = n;
      } else
        pre[i] = pre[i + 1];
    }
  }
  vector<ll> v;
  for (i = 0; i < str.length() - 1; i++) {
    if (str[i] == 'W' && str[i + 1] == 'L') {
      ll a = pre[i];
      ll b = pre[i + 1];
      b--;
      b = b - a;
      v.push_back(b);
    }
  }
  sort(v.begin(), v.end());
  ll sum = 0;
  for (i = 0; i < v.size(); i++) {
    if (sum + v[i] <= k) {
      sum += v[i];
      mp[v[i]]++;
    } else
      break;
  }
  k -= sum;
  for (i = 0; i < str.length() - 1; i++) {
    if (str[i] == 'W' && str[i + 1] == 'L') {
      ll a = pre[i];
      ll b = pre[i + 1];
      b--;
      b = b - a;
      if (mp[b]) {
        mp[b]--;
        for (j = pre[i]; j <= pre[i + 1]; j++) {
          str[j] = 'W';
        }
      }
    }
  }
  for (i = 0; i < str.length(); i++) {
    if (str[i] == 'W') {
      if (i == 0 || str[i - 1] != 'W')
        ans++;
      else if (str[i - 1] == 'W')
        ans += 2;
      else
        ans++;
    }
  }
  if (k) {
    if (ans == 0)
      ans += 2 * k - 1;
    else
      ans += 2 * k;
  }
  cout << ans << "\n";
  mp.clear();
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string str;
  ll i, j, n, m, k, t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
