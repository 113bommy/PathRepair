#include <bits/stdc++.h>
using namespace std;
double ans = 0;
int n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    ans += (double)(1 * 1.0) / (double)((n - i + 1) * 1.0);
  cout << ans;
}
