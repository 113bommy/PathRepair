#include <bits/stdc++.h>
int h, m, s, t, t1, t2, k;
using namespace std;
int main() {
  cin >> h >> m >> s >> t1 >> t2;
  h *= 5;
  if (h == 60) h = 0;
  t1 *= 5;
  t2 *= 5;
  if (t1 == 60)
    t1 = -1;
  else
    t1--;
  if (t2 == 60)
    t2 = -1;
  else
    t2--;
  while (t1 != t2) {
    t1++;
    if (t1 == h) t++;
    if (t1 == m) t++;
    if (t1 == s) t++;
    if (t1 >= 59) t1 = -1;
  }
  if (t == 3 || t == 0)
    cout << "YES";
  else
    cout << "NO";
}
