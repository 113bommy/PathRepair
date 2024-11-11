#include <bits/stdc++.h>
using namespace std;
void FAST() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  FAST();
  long long t;
  cin >> t;
  long long p;
  for (p = 0; p < t; p++) {
    long long n;
    cin >> n;
    long long arr[n];
    long long i;
    for (i = 0; i < n; i++) {
      cin >> arr[i];
    }
    long long maxi = -1;
    long long ans = -1;
    for (i = 0; i < n; i++) {
      maxi = (maxi < arr[i] ? arr[i] : maxi);
    }
    for (long long j = 1; j < n - 1; j++) {
      if (arr[j] == maxi && (arr[j] > arr[j - 1] || arr[j] > arr[j + 1])) {
        ans = j + 1;
      }
    }
    if (arr[0] == maxi && arr[0] > arr[1]) {
      ans = 1;
    }
    if (arr[n - 1] == maxi && arr[n - 1] > arr[n - 2]) {
      ans = n;
    }
    cout << ans << '\n';
  }
  return 0;
}
