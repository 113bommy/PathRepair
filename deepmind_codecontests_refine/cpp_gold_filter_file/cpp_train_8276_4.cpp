#include <bits/stdc++.h>
using namespace std;
int main() {
  int h, m;
  char c;
  int n;
  cin >> h >> c >> m >> n;
  int t = n / 60;
  n %= 60;
  m += n;
  while (m >= 60) {
    t += m / 60;
    m %= 60;
  }
  t -= (t / 24) * 24;
  t = h + t;
  t -= (t / 24) * 24;
  if (t / 10 == 0)
    cout << 0 << t << c;
  else
    cout << t << c;
  if (m / 10 == 0)
    cout << 0 << m;
  else
    cout << m;
  return 0;
}
