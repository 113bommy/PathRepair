#include <bits/stdc++.h>
using namespace std;
const unsigned long long int nmax = 1e5 + 69;
unsigned long long int dif2[nmax] = {0};
unsigned long long int a[nmax] = {0}, dif[nmax] = {0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  unsigned long long int n, m, k;
  cin >> n >> m >> k;
  for (unsigned long long int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (unsigned long long int i = 1; i <= n; i++) {
    dif[i] = a[i] - a[i - 1];
  }
  vector<pair<pair<unsigned long long int, unsigned long long int>,
              unsigned long long int>>
      v(m + 1 + 1);
  for (unsigned long long int i = 1; i <= m; i++) {
    cin >> v[i].first.first >> v[i].first.second >> v[i].second;
  }
  for (unsigned long long int i = 1; i <= k; i++) {
    unsigned long long int l, r;
    cin >> l >> r;
    dif2[l]++;
    dif2[r + 1]--;
  }
  for (unsigned long long int i = 1; i <= m; i++) {
    dif2[i] += dif2[i - 1];
  }
  for (unsigned long long int i = 1; i <= m; i++) {
    dif[v[i].first.first] += v[i].second * dif2[i];
    dif[v[i].first.second + 1] -= v[i].second * dif2[i];
  }
  unsigned long long int ans = 0;
  for (unsigned long long int i = 0; i < n; i++) {
    ans += dif[i + 1];
    cout << ans << " ";
  }
  cout << "\n";
}
