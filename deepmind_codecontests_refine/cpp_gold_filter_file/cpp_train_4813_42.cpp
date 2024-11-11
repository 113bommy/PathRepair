#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  vector<set<int> > v(20000 + 1);
  for (int i = 1; i <= 20000; i++) {
    for (int j = 1; j <= sqrt(i); j++) {
      if (i % j == 0) {
        if (j != i / j) {
          v[i].insert(j);
          v[i].insert(i / j);
        } else
          v[i].insert(j);
      }
    }
  }
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int min1 = 1e9, fa, fb, fc;
    for (int i = 1; i <= 20000; i++) {
      int tmp = 0, xx;
      set<int>::iterator it, itr;
      if (b > i)
        tmp += b - i;
      else if (b < i)
        tmp += i - b;
      if (c % i != 0) {
        xx = c / i;
        xx = xx * i;
        tmp += min(c - xx, xx + i - c);
      }
      if (a >= i)
        tmp += a - i;
      else {
        it = v[i].lower_bound(a);
        if (it != v[i].begin()) {
          itr = v[i].lower_bound(a);
          itr--;
          tmp += min(*it - a, a - *itr);
        } else
          tmp += *it - a;
      }
      if (tmp < min1) {
        min1 = tmp;
        fb = i;
        if (c % i == 0)
          fc = c;
        else if (c - xx < xx + i - c)
          fc = xx;
        else
          fc = xx + i;
        if (a >= i)
          fa = i;
        else if (it == v[i].begin())
          fa = *it;
        else {
          if (*it - a < a - *itr)
            fa = *it;
          else
            fa = *itr;
        }
      }
    }
    cout << min1 << "\n" << fa << " " << fb << " " << fc << "\n";
  }
  return 0;
}
