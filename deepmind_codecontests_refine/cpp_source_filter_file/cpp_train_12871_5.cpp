#include <bits/stdc++.h>
using namespace std;
const long long int mx = 1e6 + 50;
bool tot[10000050];
vector<int> prime;
void seive() {
  for (int i = 2; i * i <= mx; i++) {
    if (!tot[i]) {
      for (int j = (2 * i); j <= mx; j += i) {
        tot[j] = true;
      }
    }
  }
  for (int i = 2; i <= mx; i++) {
    if (!tot[i]) {
      prime.push_back(i);
    }
  }
}
vector<int> g[mx];
map<int, bool> mp;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  seive();
  cin >> n >> m;
  long long int sum = 0;
  for (int i = 1; i < n - 1; i++) {
    sum += 2;
  }
  int p = upper_bound(prime.begin(), prime.end(), sum) - prime.begin() + 1;
  int x = prime[p] - sum;
  cout << 2 << " " << prime[p] << endl;
  cout << 1 << " " << n << " " << 2 << endl;
  for (int i = 2; i <= n - 1; i++) {
    cout << 1 << " " << i << " " << ((i == 2) ? x : 2) << endl;
  }
  m -= n - 1;
  long long int tot = (int)1e6 + 10;
  int j = 2;
  mp[1] = true;
  int t = 3;
  int f = 0;
  for (int i = 2; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (f == m) {
        return 0;
      }
      f++;
      cout << i << " " << j << " " << (++tot) << endl;
    }
  }
  return 0;
}
