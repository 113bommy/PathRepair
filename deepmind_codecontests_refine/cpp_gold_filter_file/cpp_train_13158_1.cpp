#include <bits/stdc++.h>
using namespace std;
double PI = 3.1415926535897932384626;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, k;
  cin >> n >> k;
  vector<long long> arr(n + 10, 0), prefix(n + 10, 0), suf(n + 10, 0);
  for (long long i = 1; i <= n; i++) {
    cin >> arr[i];
    prefix[i] = prefix[i - 1] + arr[i];
  }
  for (long long i = n - k; i >= 0; i--) {
    suf[i + 1] = max(suf[i + 2], prefix[i + k] - prefix[i]);
  }
  long long one = -1, two = -1, cry = INT_MIN, hehe = -1;
  for (long long i = 1; i <= n - 2 * k + 1; i++) {
    long long j = i + k - 1;
    if ((suf[j + 1] + prefix[j] - prefix[i - 1]) > cry) {
      one = i;
      hehe = suf[j + 1];
      cry = suf[j + 1] + prefix[j] - prefix[i - 1];
    }
  }
  for (long long u = one + k; u <= n; u++) {
    if ((prefix[u + k - 1] - prefix[u - 1]) == hehe) {
      two = u;
      break;
    }
  }
  cout << one << " " << two << "\n";
  return 0;
}
