#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i;
  cin >> n;
  vector<long long> arr(n);
  for (i = 0; i < n; i++) cin >> arr[i];
  vector<long long> prefix(n + 2, 0);
  prefix[0] = 0;
  for (i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] + arr[i];
  }
  long long q;
  cin >> q;
  while (q--) {
    long long a, b;
    cin >> a >> b;
    long long sum = prefix[b] - prefix[a - 1];
    long long ans = sum / 10;
    cout << ans << endl;
  }
  return 0;
}
