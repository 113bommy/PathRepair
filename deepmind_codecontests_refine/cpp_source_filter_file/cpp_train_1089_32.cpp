#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const int MX = 0;
int main() {
  long long a, b;
  cin >> a >> b;
  a++;
  long long type = 1, ans = 0;
  while (a > 1) {
    int m = pow(2, a - 2);
    if ((b > m) == type) {
      ans += pow(2, a - 1);
    } else {
      type = (b > m);
      ans++;
    }
    if (b > m) b -= m;
    a--;
  }
  cout << ans;
}
