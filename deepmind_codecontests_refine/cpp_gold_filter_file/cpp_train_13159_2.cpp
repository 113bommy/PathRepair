#include <bits/stdc++.h>
using namespace std;
int main() {
  int p[4], b, t, s[4], ansb = 0, anst = 0;
  s[0] = 0;
  s[1] = 0;
  s[2] = 0;
  s[3] = 0;
  cin >> p[0] >> p[1] >> p[2] >> p[3] >> b >> t;
  int bb[b], tt[t];
  for (int i = 0; i < b; i++) cin >> bb[i];
  for (int i = 0; i < t; i++) cin >> tt[i];
  for (int i = 0; i < b; i++) {
    if (bb[i] * p[0] <= p[1])
      s[0] += bb[i] * p[0];
    else
      s[1] += p[1];
  }
  if (s[0] + s[1] <= p[2])
    ansb = s[0] + s[1];
  else
    ansb = p[2];
  s[0] = 0;
  s[1] = 0;
  s[2] = 0;
  s[3] = 0;
  for (int i = 0; i < t; i++) {
    if (tt[i] * p[0] <= p[1])
      s[0] += tt[i] * p[0];
    else
      s[1] += p[1];
  }
  if (s[0] + s[1] <= p[2])
    anst = s[0] + s[1];
  else
    anst = p[2];
  if (anst + ansb <= p[3])
    cout << anst + ansb;
  else
    cout << p[3];
}
