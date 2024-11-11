#include <bits/stdc++.h>
using namespace std;
long long n, c, v[500001], f[500001], maxim;
vector<long long> poz[500001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    f[i] = f[i - 1];
    if (v[i] == c) f[i]++;
    poz[v[i]].push_back(i);
  }
  maxim = f[n];
  for (int d = 1; d <= 500000; d++)
    if (d != c && poz[d].size()) {
      long long summax = 1;
      long long suma = 1;
      for (int i = 1; i < poz[d].size(); i++) {
        long long p = poz[d][i];
        long long ant = poz[d][i - 1];
        suma -= (f[p - 1] - f[ant]);
        suma++;
        if (suma <= 0) suma = 1;
        summax = max(summax, suma);
      }
      if (f[n] + summax > maxim) maxim = f[n] + summax;
    }
  cout << maxim;
  return 0;
}
