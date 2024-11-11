#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  long long x1, y1;
  cin >> x1 >> y1;
  long long x2, y2;
  cin >> x2 >> y2;
  long long n;
  cin >> n;
  long long ans = 0;
  while (n--) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long s1 = a * x1 + b * y1 - c < 0;
    long long s2 = a * x2 + b * y2 - c < 0;
    if (s1 != s2) {
      ans++;
    }
  }
  cout << ans;
}
