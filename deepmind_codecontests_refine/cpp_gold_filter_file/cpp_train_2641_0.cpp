#include <bits/stdc++.h>
using namespace std;
int n, t, last, p;
string s;
inline int f(int k) {
  int t = 0;
  int need_idx = -1;
  int need_k = 0;
  int togo = s.size() - p;
  int t2 = (togo - 1) + togo;
  for (int i = 0; i < togo; i++) {
    if ((i > last) && !need_k) {
      break;
    }
    t++;
    if (s[i] == 'S') {
      k++;
      if (need_k && (need_k <= k)) {
        k -= need_k;
        t2 = min(t2, t + (togo - 1 - i) + (togo - 1 - need_idx));
        t += (i - need_idx);
        if (i < last) {
          t += (i - need_idx);
        }
        need_idx = -1;
        need_k = 0;
      }
    } else if (s[i] == 'H') {
      if (k)
        k--;
      else {
        if (need_idx < 0) need_idx = i;
        if (need_idx >= 0) {
          need_k++;
        }
      }
    }
  }
  if (need_k)
    t = numeric_limits<int>::max();
  else {
    t = min(t, t2);
  }
  return t;
};
int main(void) {
  int k = 0;
  p = 0;
  cin >> n >> t;
  cin >> s;
  int houses = 0;
  for (int i = 0; i < s.size(); i++) {
    if ('.' == s[i]) {
      p += 1;
    } else {
      p = 0;
    }
    if ('H' == s[i]) {
      last = i;
      houses++;
    }
  }
  if (last > t) {
    cout << -1 << endl;
    return 0;
  }
  int l = 0;
  int r = houses;
  int med;
  while (r - l > 1) {
    med = l + (r - l) / 2;
    int curt = f(med);
    if (curt <= t) {
      r = med;
    } else {
      l = med;
    }
  }
  k = -1;
  if (f(l) <= t) {
    k = l;
  } else if (f(r) <= t) {
    k = r;
  }
  cout << k << endl;
  return 0;
}
