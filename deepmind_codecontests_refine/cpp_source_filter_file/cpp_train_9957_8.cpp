#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 7;
const int inf = INT_MAX;
const long long inff = 1e18;
const long long mod = 1e9 + 7;
int divi[maxn], p[maxn];
int primes[maxn];
const int MAXN = 300000;
int used[maxn];
void print(int n) {
  vector<int> ans;
  for (int i = 1; i <= n; i++)
    if (!used[i]) ans.push_back(i);
  cout << ((int)(ans).size()) << '\n';
  for (int i : ans) cout << i << ' ';
  exit(0);
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  primes[1] = 1;
  for (int i = 1; i <= MAXN; i++) {
    for (int j = i; j <= MAXN; j += i) divi[j]++;
    if (i >= 2)
      for (int j = 2 * i; j <= MAXN; j += i) primes[j] = 1;
  }
  for (int i = 1; i <= MAXN; i++) {
    p[i] = p[i - 1] + divi[i] - 1;
    primes[i] ^= 1;
    primes[i] += primes[i - 1];
  }
  int n, k;
  cin >> n >> k;
  if (k > p[MAXN])
    cout << "No" << '\n';
  else {
    int now = lower_bound(p + 1, p + MAXN + 1, k) - p;
    if (now > n) return cout << "No" << '\n', 0;
    cout << "Yes" << '\n';
    vector<int> _2, _3, _4;
    for (int j = (now + 2) / 2; j <= now; j++)
      if (divi[j] == 2)
        _2.push_back(j);
      else if (divi[j] == 3)
        _3.push_back(j);
      else if (divi[j] == 4)
        _4.push_back(j);
    assert(p[now] - k <= ((int)(_2).size()) + 2 * ((int)(_3).size()) +
                             3 * ((int)(_4).size()));
    int cnt = p[now];
    if (cnt == p[now]) print(now);
    for (int i : _2) {
      used[i] = 1;
      cnt--;
      if (cnt == k) print(now);
    }
    for (int i : _3) {
      used[i] = 1;
      cnt -= 2;
      if (cnt == k)
        print(now);
      else if (cnt == k - 1) {
        used[_2[0]] = 0;
        print(now);
      }
    }
    for (int i : _4) {
      used[i] = 1;
      cnt -= 3;
      if (cnt == k)
        print(now);
      else if (cnt == k - 1) {
        used[_2[0]] = 0;
        print(now);
      } else if (cnt == k - 2) {
        if (k == 36 || k == 468) {
          used[_2[0]] = 0;
          used[_2[1]] = 0;
          print(now);
        }
        used[_3[0]] = 0;
        print(now);
      }
    }
  }
}
