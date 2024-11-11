#include <bits/stdc++.h>
using namespace std;
long long A, B;
long long calNum(int x) { return A + B * (x - 1); }
long long calSum(int a, int b) {
  return (b - a + 1) * (calNum(a) + calNum(b)) / 2;
}
int main() {
  int n;
  long long l, m, t, sum;
  cin >> A >> B >> n;
  for (int i = 0; i < n; i++) {
    cin >> l >> t >> m;
    sum = t * m;
    if (calNum(l) > t) {
      cout << -1 << endl;
    } else {
      int r = 1e6;
      int mid;
      int lll = l, rrr = r;
      while (lll != rrr) {
        mid = (lll + rrr) / 2;
        if (lll == mid) {
          if (calNum(rrr) <= t)
            break;
          else {
            mid = rrr;
            break;
          }
        }
        if (calNum(mid) == t) break;
        if (calNum(mid) < t)
          lll = mid;
        else
          rrr = mid;
      }
      rrr = mid;
      lll = l;
      while (lll != rrr) {
        mid = (lll + rrr) / 2;
        if (mid == lll) {
          if (calSum(l, rrr) <= sum)
            break;
          else {
            rrr = lll;
            break;
          }
        }
        if (calSum(l, mid) == sum) {
          rrr = mid;
        }
        if (calSum(l, mid) < sum)
          lll = mid;
        else
          rrr = mid;
      }
      cout << rrr << endl;
    }
  }
}
