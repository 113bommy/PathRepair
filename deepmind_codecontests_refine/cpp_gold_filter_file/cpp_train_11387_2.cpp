#include <bits/stdc++.h>
using namespace std;
long long int max(long long int a, long long int b) {
  if (a > b)
    return a;
  else
    return b;
}
long long int min(long long int a, long long int b) {
  if (a < b)
    return a;
  else
    return b;
}
long long int M;
long long int binpow(long long int a, long long int b) {
  if (b == 0) return 1;
  long long int res = binpow(a, b / 2);
  if (b % 2)
    return (((((res % M) * (res % M)) % M) % M) * (a % M)) % M;
  else
    return ((res % M) * (res % M)) % M;
}
long long int inf = numeric_limits<long long int>::max();
long long int MAXN = 100000;
vector<long long int> fact(2 * MAXN + 1, 1);
void factc() {
  for (long long int i = 1; i <= 2 * MAXN; i++) {
    if (i % 2 == 0) {
      long long int mlp = i / 2;
      fact[i] = ((fact[i - 1] % M) * (mlp % M)) % M;
    } else {
      fact[i] = ((fact[i - 1] % M) * (i % M)) % M;
    }
  }
}
void solve() {
  long long int n, a;
  cin >> n;
  map<long long int, map<long long int, long long int>> xs;
  for (long long int i = 1; i <= n; i++) {
    cin >> a;
    auto it = xs.find(a);
    if (it == xs.end()) {
      map<long long int, long long int> inew;
      inew.insert(make_pair(i, 1));
      xs.insert(make_pair(a, inew));
    } else {
      auto it2 = (it->second).find(i);
      if (it2 == (it->second).end())
        (it->second).insert(make_pair(i, 1));
      else
        (it2->second)++;
    }
  }
  for (long long int i = 1; i <= n; i++) {
    cin >> a;
    auto it = xs.find(a);
    if (it == xs.end()) {
      map<long long int, long long int> inew;
      inew.insert(make_pair(i, 1));
      xs.insert(make_pair(a, inew));
    } else {
      auto it2 = (it->second).find(i);
      if (it2 == (it->second).end())
        (it->second).insert(make_pair(i, 1));
      else
        (it2->second)++;
    }
  }
  cin >> M;
  factc();
  long long int ans = 1;
  for (auto it = xs.begin(); it != xs.end(); it++) {
    long long int ycnt = 0, dcnt = 0;
    for (auto it2 = (it->second).begin(); it2 != (it->second).end(); it2++) {
      ycnt += it2->second;
      if (it2->second == 2) dcnt++;
    }
    ans = ((ans % M) * (fact[ycnt] % M)) % M;
    ans = ((ans % M) * (binpow(2, (ycnt / 2) - dcnt) % M)) % M;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
