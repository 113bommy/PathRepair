#include <bits/stdc++.h>
using namespace std;
int n, d, a[105], m, profit;
int main() {
  cin >> n >> d;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  cin >> m;
  for (int i = 0; i < min(n, m); i++) profit += a[i];
  if (m > n) profit -= (m - n) * d;
  cout << profit << endl;
}
