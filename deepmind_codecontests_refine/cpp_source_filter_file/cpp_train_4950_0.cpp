#include <bits/stdc++.h>
using namespace std;
int i, j, n, k, freq[1000005], x;
bool c[2005];
vector<int> primes, fact;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (i = 1; i <= n; ++i) cin >> x, freq[x] = 1;
  for (i = 2; i <= 2000; ++i)
    if (!c[i]) {
      primes.push_back(i);
      for (j = i + i; j <= 2000; j += i) c[j] = 1;
    }
  for (auto it : primes) {
    if (it * it > k) break;
    if (k % it) continue;
    int sum = 0;
    while (k % it == 0) k /= it, sum += it;
    fact.push_back(sum);
  }
  if (k > 1) fact.push_back(k);
  for (auto it : fact) {
    bool ok = 0;
    for (i = it; i <= 1000000; i += it)
      if (freq[i]) ok = 1, i = 1e9;
    if (!ok) return cout << "No\n", 0;
  }
  cout << "Yes\n";
  return 0;
}
