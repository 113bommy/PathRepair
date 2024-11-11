#include <bits/stdc++.h>
using namespace std;
long long int sumr[1003], sumc[1003], ansr[1000006], ansc[1000006];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  ;
  long long int n, m, k, p, a;
  cin >> n >> m >> k >> p;
  for (long long int i = 0; i <= n - 1; i++) {
    for (long long int j = 0; j <= m - 1; j++) {
      cin >> a;
      sumr[i] += a;
      sumc[j] += a;
    }
  }
  multiset<long long int> row, col;
  for (long long int i = 0; i <= n - 1; i++) {
    row.insert(sumr[i]);
  }
  for (long long int i = 0; i <= m - 1; i++) {
    col.insert(sumc[i]);
  }
  for (long long int i = 1; i <= k; i++) {
    ansr[i] = ansr[i - 1];
    auto rit = row.end();
    rit--;
    ansr[i] += *rit;
    row.insert(*rit - p * m);
    row.erase(row.find(*rit));
  }
  for (long long int i = 1; i <= k; i++) {
    ansc[i] = ansc[i - 1];
    auto cit = col.end();
    cit--;
    ansc[i] += *cit;
    col.insert(*cit - p * n);
    col.erase(col.find(*cit));
  }
  long long int ans = LLONG_MIN;
  for (long long int i = 0; i <= k; i++) {
    ans = max(ans, ansr[i] + ansc[k - i] - i * (k - i) * p);
  }
  cout << ans << endl;
  return 0;
}
