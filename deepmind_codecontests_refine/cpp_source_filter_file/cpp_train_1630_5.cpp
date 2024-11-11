#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  unsigned long long k, d, t;
  cin >> k >> d >> t;
  if (k % d == 0) {
    cout << t;
  } else {
    unsigned long long t1 = 2 * t;
    unsigned long long temp = k / d;
    unsigned long long temp1 = (temp + 1) * d;
    unsigned long long temp2 = temp1 - k;
    unsigned long long temp3 = k * 2;
    unsigned long long yedu = temp3 + temp2;
    unsigned long long temp4 = t1 / yedu;
    long double rem = t1 - (yedu * temp4);
    if (rem <= 0)
      cout << t1 << "\n";
    else {
      if (temp3 >= rem) {
        rem /= 2;
        cout << setprecision(std::numeric_limits<double>::digits10 + 1) << fixed
             << (long double)((long double)((temp2 + k)) * temp4 +
                              (long double)rem);
      } else {
        rem -= temp3;
        cout << setprecision(std::numeric_limits<double>::digits10 + 1) << fixed
             << (long double)((long double)((temp2 + k) * temp4) +
                              (long double)rem + (long double)(k));
      }
    }
  }
  return 0;
}
