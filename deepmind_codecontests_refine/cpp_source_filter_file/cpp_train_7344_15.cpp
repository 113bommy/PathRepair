#include <bits/stdc++.h>
using namespace std;
long long n, b, d;
long long t;
int main() {
  cin >> n >> b >> d;
  long long s = 0;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &t);
    if (t <= b) {
      s += t;
      if (s > d) {
        s -= d;
        ans++;
      }
    }
  }
  cout << ans << endl;
}
