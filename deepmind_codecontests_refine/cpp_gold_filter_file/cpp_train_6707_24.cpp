#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n, t, i, e;
  n = count(s.begin(), s.end(), 'n');
  e = count(s.begin(), s.end(), 'e');
  t = count(s.begin(), s.end(), 't');
  i = count(s.begin(), s.end(), 'i');
  if (n % 2 == 1 && n > 3) {
    if (e >= n / 2 * 3) {
      n = e = n / 2;
    } else {
      n /= 3;
      e /= 3;
    }
  } else if (n > 3) {
    if (e >= (n / 2 - 1) * 3) {
      n = e = n / 2 - 1;
    } else {
      n /= 3;
      e /= 3;
    }
  } else {
    n /= 3;
    e /= 3;
  }
  int min = n < e ? n : e;
  int min1 = t < i ? t : i;
  cout << (min < min1 ? min : min1);
}
