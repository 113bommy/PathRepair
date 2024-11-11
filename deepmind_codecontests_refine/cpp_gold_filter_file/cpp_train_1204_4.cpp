#include <bits/stdc++.h>
using namespace std;
const int N = int(1e5);
vector<int> pr;
map<int, int> fac;
void sieve() {
  bitset<N> bs;
  for (int i = 2; i <= N; ++i) {
    if (bs[i]) continue;
    pr.push_back(i);
    for (int j = 2 * i; j <= N; j += i) {
      bs[j] = 1;
    }
  }
}
void fact(int n) {
  for (int i = 0; i < pr.size() && pr[i] * pr[i] <= n; ++i) {
    if (n % pr[i]) continue;
    fac[pr[i]] = fac[pr[i]] + 1;
    while (n % pr[i] == 0) {
      n /= pr[i];
    }
  }
  if (n > 1) {
    fac[n] = fac[n] + 1;
  }
}
int main() {
  sieve();
  int n, t;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &t);
    fact(t);
  }
  int ans = 0;
  for (map<int, int>::iterator it = fac.begin(); it != fac.end(); ++it) {
    ans = max(ans, it->second);
  }
  printf("%d\n", max(1, ans));
}
