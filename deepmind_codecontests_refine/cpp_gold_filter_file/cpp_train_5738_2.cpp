#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;
long long arr[MAXN], x[MAXN];
int main() {
  int n;
  cin >> n;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    x[i] = arr[i] - 1;
  }
  ans = arr[n - 1] - 1;
  for (int i = n - 2; i >= 0; i--) {
    x[i] += x[i + 1];
    ans += x[i];
  }
  ans += n;
  cout << ans << endl;
}
