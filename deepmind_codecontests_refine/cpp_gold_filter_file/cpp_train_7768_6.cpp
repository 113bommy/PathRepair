#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int MAXN = 1e5 + 5;
const long long MOD = 1e9 + 7;
int a[MAXN];
int main() {
  int n, x;
  cin >> n >> x;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  sum = sum + n - 1;
  if (sum == x)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
