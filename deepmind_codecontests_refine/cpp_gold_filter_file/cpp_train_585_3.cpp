#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k, d, t;
  cin >> k >> d >> t;
  if (k > d) {
    if (k % d == 0) {
      double ans = t;
      printf("%.15f", ans);
      return (0);
    } else {
      double rem = d - (k % d);
      double temp = rem / 2.0;
      double kaj_hoiche = k + temp;
      double total_time = k + rem;
      long long lagbe = t / kaj_hoiche;
      kaj_hoiche = lagbe * kaj_hoiche;
      double kaj_baki_ache = t - kaj_hoiche;
      double ans = lagbe * total_time;
      if (kaj_baki_ache <= k) {
        ans += kaj_baki_ache;
      } else {
        ans += k;
        kaj_baki_ache -= k;
        ans += (kaj_baki_ache * 2.0);
      }
      printf("%.15f", ans);
      return (0);
    }
  } else {
    double unit_kaj = k + (d - k) / 2.0;
    long long needed = t / unit_kaj;
    double ans = needed * d;
    double kaj_baki_ache = t - (unit_kaj * needed);
    if (kaj_baki_ache <= k) {
      ans += kaj_baki_ache;
    } else {
      ans += k;
      kaj_baki_ache = kaj_baki_ache - k;
      ans += (kaj_baki_ache * 2.0);
    }
    printf("%.15f", ans);
    return (0);
  }
}
