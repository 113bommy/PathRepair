#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m, r;
  cin >> n >> m >> r;
  long long arr[n], brr[m];
  for (long long i = 0; i < n; i++) cin >> arr[i];
  for (long long j = 0; j < m; j++) cin >> brr[j];
  long long buy = *min_element(arr, arr + n);
  long long x = r / buy, y = r % buy;
  cout << max(r, (*max_element(brr, brr + m)) * x + y) << "\n";
}
