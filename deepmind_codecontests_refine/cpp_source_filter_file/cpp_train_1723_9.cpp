#include <bits/stdc++.h>
using namespace std;
long long freq[3000001] = {0};
long long arr[3000001] = {0};
long long ans[3000001] = {0};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    freq[v[i]]++;
  }
  for (long long i = 1; i <= 3000000; i++) {
    for (long long j = 1; j * i <= 3000000; j++) {
      if (i == j)
        arr[i * j] += freq[i] * (freq[i] - 1);
      else
        arr[i * j] += freq[i] * freq[j];
    }
  }
  ans[1] = n * (n - 1);
  long long sum = arr[1];
  for (long long i = 1; i <= 3000000; i++) {
    ans[i] = n * (n - 1) - sum;
    sum += arr[i];
  }
  long long q;
  cin >> q;
  while (q--) {
    long long x;
    cin >> x;
    cout << ans[x] << '\n';
  }
}
