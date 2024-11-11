#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int a, b, c, d;
  cin >> a >> b >> c >> d;
  long long int ans = (a + 2) + (b * 2);
  long long int ans1 = (d * 2) + (c + 2);
  if (a > c || c > a) ans1 += abs(b - c);
  cout << ans + ans1 << "\n";
}
