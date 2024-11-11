#include <bits/stdc++.h>
using namespace std;
long long int n, p, m, k, x;
long long int a[200005 + 2] = {0};
void solve() {
  long long int c = 0;
  a[0] = 10000000000;
  long long int sexyass = 0;
  for (long long int i = 1; i <= n; i++) {
    if (a[i] < 0) c++;
    if (abs(a[i]) < abs(a[sexyass])) sexyass = i;
  }
  if (c % 2 == 0) {
    long long int kl = abs(a[sexyass]) / x + 1;
    kl = min(k, kl);
    k -= kl;
    if (a[sexyass] < 0)
      a[sexyass] += kl * x;
    else
      a[sexyass] -= kl * x;
  }
  set<pair<long long int, long long int> > s;
  for (long long int i = 1; i <= n; i++) {
    s.insert({abs(a[i]), i});
  }
  while (k > 0) {
    k -= 1;
    long long int p = s.begin()->second;
    if (a[p] >= 0)
      a[p] += x;
    else
      a[p] -= x;
    s.erase(s.begin());
    s.insert({abs(a[p]), p});
  }
  for (long long int i = 1; i <= n; i++) cout << a[i] << " ";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k >> x;
  for (long long int i = 1; i <= n; i++) cin >> a[i];
  solve();
}
