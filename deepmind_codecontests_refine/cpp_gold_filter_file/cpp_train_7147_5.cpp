#include <bits/stdc++.h>
using namespace std;
const long long m = 998244353;
int n;
int a[100005];
int b[100005];
int main() {
  int k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  int sum = 0;
  int maxs = 0;
  for (int i = 1; i <= k && i <= n; i++) {
    if (b[i] == 0) {
      maxs += a[i];
    }
  }
  sum = maxs;
  int begin = 1;
  if (n == 1) {
    cout << a[1] << endl;
    return 0;
  }
  for (int i = 2; i <= n - k + 1; i++) {
    if (b[i - 1] == 0) sum -= a[i - 1];
    if (b[i + k - 1] == 0) sum += a[i + k - 1];
    if (sum > maxs) {
      maxs = sum;
      begin = i;
    }
  }
  int num = 0;
  for (int i = 1; i <= n; i++) {
    if (b[i] == 1)
      num += a[i];
    else {
      if (i < begin || i > begin + k - 1)
        continue;
      else
        num += a[i];
    }
  }
  cout << num;
}
