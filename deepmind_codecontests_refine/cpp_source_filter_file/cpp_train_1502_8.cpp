#include <bits/stdc++.h>
using namespace std;
long long maxHandBurger(string s1, long long nb, long long ns, long long nc,
                        long long pb, long long ps, long long pc, long long r) {
  long long cb = 0, cs = 0, cc = 0;
  for (char ch : s1) {
    if (ch == 'B')
      cb++;
    else if (ch == 'S')
      cs++;
    else
      cc++;
  }
  long long low = 1, high = (long long)1e12, mid;
  long long ans = 0;
  while (low <= high) {
    mid = low + (high - low) / 2;
    long long bread = (cb * mid - nb) * pb;
    long long sausage = (cs * mid - ns) * ps;
    long long cheese = (cc * mid - nc) * pc;
    bread = bread > 0 ? bread : 0;
    sausage = sausage > 0 ? sausage : 0;
    cheese = cheese > 0 ? cheese : 0;
    long long price = bread + sausage + cheese;
    if (price == r)
      return mid;
    else if (price < r) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return ans;
}
int main() {
  long long nb, ns, nc, pb, ps, pc, r;
  string in;
  cin >> in;
  cin >> nb >> ns >> nc;
  cin >> pb >> ps >> pc;
  cin >> r;
  cout << maxHandBurger(in, nb, ns, nc, pb, ps, pc, r);
}
