#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, h, m2, h2;
  char ch;
  cin >> h >> ch >> m;
  cin >> h2 >> ch >> m2;
  int h_raz = h2 - h >= 0 ? h2 - h : 23 + h2 - h;
  int m_raz = m2 - m;
  int raz_curr = (h2 == h && m2 == m) ? 60 * 24 : h_raz * 60 + m_raz;
  raz_curr /= 2;
  int per = m + raz_curr % 60 > 59 ? 1 : 0;
  string str_h = to_string((h + raz_curr / 60 + per) % 24);
  if (str_h.size() == 1) str_h = "0" + str_h;
  string str_m = to_string((m + raz_curr % 60));
  if (str_m.size() == 1) str_m = "0" + str_m;
  cout << str_h << ch << str_m;
  return 0;
}
