#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a > b)
    return gcd(a % b, b);
  else
    return gcd(b % a, a);
}
int main() {
  long long t1, t2, x1, x2, t0, temp1, temp2, temp, y1, y2, ttt;
  double a, b, c, d, x, tt, dif;
  int t;
  double mini = 10000000.0;
  int ans1 = 0, ans2 = 0, k;
  cin >> t1 >> t2 >> x1 >> x2 >> t0;
  temp2 = t0 - t1;
  temp1 = t2 - t0;
  if (t1 == t0 && t1 == t2) {
    ans1 = x1;
    ans2 = x2;
  } else if (t1 == t0) {
    ans1 = x1;
  } else if (t2 == t0)
    ans2 = x2;
  else {
    t = gcd(temp1, temp2);
    temp1 /= t;
    temp2 /= t;
    if (temp1 <= x1 && temp2 <= x2) {
      if (x1 < x2)
        k = x2;
      else
        k = x1;
      for (int i = 1; i <= k; i++) {
        if (temp1 * i <= x1 && temp2 * i <= x2) {
          if (ans1 + ans2 < temp1 * i + temp2 * i) {
            ans1 = temp1 * i;
            ans2 = temp2 * i;
          }
        }
      }
    } else {
      x = 1.0 * temp2 / (double)temp1;
      for (int i = x1; i >= 1; i--) {
        temp = i * temp2 / temp1;
        if (temp <= 1000000) {
          temp = i * temp2;
          if (temp % temp1 == 0) {
            y1 = i;
            y2 = temp / temp1;
            if (ans1 + ans2 < y1 + y2 && y2 <= x2) {
              ans1 = y1;
              ans2 = y2;
              mini = 0.0;
            }
          } else {
            tt = x * i;
            ttt = (long long)tt + 1;
            dif = 1.0 * ttt / (double)i - x;
            if (ttt <= x2 && mini > dif && dif >= 0.0) {
              ans1 = i;
              ans2 = ttt;
              mini = dif;
            } else if (ttt <= x2 && mini == dif && dif >= 0) {
              if (ans1 + ans2 < i + ttt) {
                ans1 = i;
                ans2 = ttt;
              }
            }
          }
        }
      }
      if (mini > (double)temp2) {
        if (ans1 + ans2 < y1 + y2) {
          ans1 = 0;
          ans2 = x2;
        }
      }
    }
  }
  cout << ans1 << " " << ans2 << endl;
  scanf(" ");
}
