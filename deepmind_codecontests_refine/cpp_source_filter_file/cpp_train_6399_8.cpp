#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  long long n, ans = 0;
  cin >> n;
  while (n--) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long s1, s2;
    s1 = a * x1 + b * y1 + c;
    s2 = a * x2 + b * y2 + c;
    if ((s1 > 0 && s2 < 0) || (s1 > 0 && s1 < 0)) ans++;
  }
  cout << ans << endl;
  return 0;
}
