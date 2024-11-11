#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int mx = 0;
  string f;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    string k;
    cin >> k;
    int p, m, a, b, c, d, e;
    cin >> p >> m >> a >> b >> c >> d >> e;
    p *= 100;
    m *= 50;
    sum = p - m;
    sum = sum + a + b + c + d + e;
    if (sum > mx) {
      f = k;
      mx = sum;
    }
  }
  cout << f;
}
