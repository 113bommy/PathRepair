#include <bits/stdc++.h>
using namespace std;
long long a[10], num[10];
const long long inf =
    (long long)9 * 10000 * 10000 * 10000 * 10000 * 100 + (long long)10;
long long sum, ans = inf;
long long make(long long a, long long b, long long c, long long numa,
               long long numb, long long numc) {
  long long dif_ab, dif_ac, newc, newb;
  dif_ab = numb - numa;
  dif_ac = numc - numa;
  newb = a + dif_ab;
  newc = a + dif_ac;
  if (newc < c) return inf;
  if (newb < b) return inf;
  return (a + newb + newc) - sum;
}
int main() {
  cin >> a[1] >> a[2] >> a[3];
  sum = a[1] + a[2] + a[3];
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) {
      num[1] = 0;
      num[2] = 0;
      num[3] = 0;
      for (int t = 1; t <= 3; t++) {
        if (t > i) num[t]++;
        if (t <= j) num[t]++;
      }
      long long fr = make(a[1], a[2], a[3], num[1], num[2], num[3]);
      ans = min(ans, fr);
      long long sec = make(a[2], a[1], a[3], num[2], num[1], num[3]);
      ans = min(ans, sec);
      long long trd = make(a[3], a[1], a[2], num[3], num[1], num[2]);
      ans = min(ans, trd);
    }
  cout << ans;
}
