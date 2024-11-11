#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(!cin.tie(0));
  cout << setprecision(20) << fixed;
  int t;
  cin >> t;
  while (t--) {
    double d, c, i = 1;
    cin >> d >> c;
    double b = d - c;
    b = i / b;
    c = i / c;
    d = -i / d;
    b += c + d;
    double cpd = c + d;
    double cpd4 = cpd * 4;
    double ctd4 = c * d;
    int k;
    cin >> k;
    while (--k) {
      b = b + cpd + sqrt(b * cpd4 + ctd4);
    }
    cout << i / b << '\n';
  }
}
