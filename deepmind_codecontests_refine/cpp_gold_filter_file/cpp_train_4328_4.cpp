#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  long long k, m1 = 0, m2 = 0, t1 = 0, t2 = 0, l1 = 0, l2 = 0, s1[t], s2[t],
               o1 = 0, o2 = 0;
  for (int i = 0; i < t; i++) {
    cin >> s1[i] >> s2[i];
    l1 = l1 + s1[i];
    l2 = l2 + s2[i];
    k = s1[i] - s2[i];
    m1 = min(k, m1);
    m2 = max(k, m2);
    if (m2 == s1[i] - s2[i]) {
      t2 = i;
    }
    if (m1 == s1[i] - s2[i]) {
      t1 = i;
    }
  }
  long long l = l1 - l2, ans = 0;
  if (l > 0 && l - m1 - m2 >= 0) {
    if (m1 < 0) {
      ans = t1 + 1;
    } else if (m1 == 0) {
      ans = 0;
    }
  } else if (l > 0 && l - m1 - m2 < 0) {
    ans = t2 + 1;
  } else if (l == 0) {
    if (m2 + m1 > 0) {
      ans = t2 + 1;
    } else if (m1 + m2 <= 0) {
      ans = t1 + 1;
    }
  } else if (l < 0 && l - m1 + m2 <= 0) {
    if (m2 > 0) {
      ans = t2 + 1;
    } else {
      ans = 0;
    }
  } else if (l < 0 && l - m1 + m2 > 0) {
    ans = t1 + 1;
  }
  cout << ans << endl;
}
