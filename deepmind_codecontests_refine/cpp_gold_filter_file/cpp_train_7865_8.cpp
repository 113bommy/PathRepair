#include <bits/stdc++.h>
using namespace std;
int primes[10000010];
int p;
int low[10000010];
void ciur();
set<int> s;
int main() {
  ciur();
  int n, x, c;
  cin >> n >> x;
  while (n--) {
    cin >> c;
    s.insert(c);
  }
  if (x == 2) {
    cout << 0;
    return 0;
  }
  if (s.find(1) != s.end()) {
    cout << 1;
    return 0;
  }
  if (primes[p] < x) {
    cout << -1;
    return 0;
  }
  int ans(0);
  for (int i(1); primes[i] < x; i++) {
    ans++;
    if (s.find(primes[i]) == s.end()) {
      cout << -1;
      return 0;
    }
  }
  cout << ans;
  return 0;
}
void ciur() {
  for (int i(2); i <= 10000000; i++) {
    if (!low[i]) low[i] = i, primes[++p] = i;
    for (int j(1); j <= p && primes[j] <= low[i] && i * primes[j] <= 10000000;
         j++)
      low[i * primes[j]] = primes[j];
  }
}
