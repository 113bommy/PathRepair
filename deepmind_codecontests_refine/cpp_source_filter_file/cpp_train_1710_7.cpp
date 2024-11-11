#include <bits/stdc++.h>
const long long MOD = 1000000007;
using namespace std;
vector<long long> pr;
long long lp[10000001];
long long sum[10000001];
int main() {
  for (int i = 2; i <= 1000000; i++) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= 10000000;
         j++) {
      lp[i * pr[j]] = pr[j];
    }
  }
  long long n;
  cin >> n;
  long long arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
    while (arr[i] != 1) {
      long long div = lp[arr[i]];
      sum[div]++;
      while (arr[i] % div == 0) arr[i] /= div;
    }
  }
  for (int i = 1; i < 1000001; i++) {
    sum[i] += sum[i - 1];
  }
  long long m;
  cin >> m;
  long long l, r;
  for (int i = 0; i < m; i++) {
    scanf("%lld %lld", &l, &r);
    if (l > 1e7) l = 1e7;
    if (r > 1e7) r = 1e7;
    printf("%lld\n", sum[r] - sum[l - 1]);
  }
}
