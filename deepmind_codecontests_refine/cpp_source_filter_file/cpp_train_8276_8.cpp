#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  string a;
  cin >> a;
  long long h, m;
  h = (((int)a[0] - '0') * 10) + ((int)a[1] - '0');
  m = (((int)a[3] - '0') * 10) + ((int)a[4] - '0');
  cin >> t;
  long long hh = 0, mm = 0;
  hh += t / 60;
  mm += t % 60;
  h += hh;
  if (h >= 24) {
    h = h - 24;
  }
  m += mm;
  if (m >= 60) {
    m = m - 60;
    h++;
    if (h >= 24) {
      h = h - 24;
    }
  }
  if (h < 10 && m < 10) {
    cout << 0 << h << ":" << 0 << m;
  } else if (h < 10 && m >= 10) {
    cout << 0 << h << ":" << m;
  } else if (h >= 10 && m < 10) {
    cout << h << ":" << 0 << m;
  } else
    cout << h << ":" << m;
  return 0;
}
