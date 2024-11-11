#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long n, i, j, k;
  cin >> n;
  long long ar[n + 1], pre[n + 1], suff[n + 1];
  for (i = 0; i < n; i++) {
    cin >> ar[i];
  }
  long long mx = INT_MIN;
  pre[0] = 1;
  suff[n - 1] = 1;
  for (i = 1; i < n; i++) {
    if (ar[i] > ar[i - 1]) {
      pre[i] = pre[i - 1] + 1;
      mx = max(mx, pre[i]);
    } else {
      pre[i] = 1;
    }
  }
  for (i = n - 2; i >= 0; i--) {
    if (ar[i] < ar[i + 1]) {
      suff[i] = suff[i + 1] + 1;
      mx = max(mx, suff[i]);
    } else {
      suff[i] = 1;
    }
  }
  for (i = 1; i < n - 1; i++) {
    if (ar[i - 1] < ar[i + 1]) {
      mx = max(mx, pre[i - 1] + suff[i + 1]);
    }
  }
  cout << mx << endl;
  return 0;
}
