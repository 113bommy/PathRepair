#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 4;
long long int a[maxn], dif1[maxn], dif2[maxn];
long long int kadane(long long int arr[], int n) {
  long long int ans = -2e9, curr_max = -2e9;
  for (int i = 1; i < n; i++) {
    curr_max = max(arr[i], curr_max + arr[i]);
    ans = max(curr_max, ans);
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long int tog = -1LL;
  for (int i = 1; i < n; i++) {
    dif1[i] = tog * abs(a[i + 1] - a[i]);
    dif2[i] = -1LL * dif1[i];
    tog = -1 * tog;
  }
  long long int ans = max(kadane(dif1, n), kadane(dif2, n));
  cout << ans;
  return 0;
}
