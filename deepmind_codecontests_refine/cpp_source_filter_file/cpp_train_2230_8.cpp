#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1000 * 100 + 100;
int a[maxn];
int main() {
  int n, m, f, g, sum = 0, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == 0)
      ans++;
    else
      sum += ans;
  }
  cout << sum;
}
