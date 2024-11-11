#include <bits/stdc++.h>
using namespace std;
int n;
long long int s, sum = 0;
const int maxn = 200100;
int a[maxn];
int ans[maxn];
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 0; i < n; i++) {
    long long int len = s - (sum - a[i]);
    if (len <= 0) len = 1;
    if (a[i] - len <= ((s - len) - (n - 1))) {
      ans[i] = len - 1;
    } else {
      ans[i] = a[i] - ((s - len) - (n - 1)) - 1;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
