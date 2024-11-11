#include <bits/stdc++.h>
using namespace std;
bool w[100002], l[100002];
int chk(long long s, long long e) {
  if (e == s) return 0;
  if (e == s + 1) return 1;
  if (e & 1) {
    if (s & 1) return 0;
    return 1;
  }
  if (s <= e / 4) return chk(s, e / 4);
  if (s > (e / 4) * 2)
    return ((e - s) & 1);
  else
    return 1;
}
int lck(long long s, long long e) {
  if (s * 2 > e) return 1;
  long long w = e / 2 + 3;
  while (w * 2 > e) w--;
  return chk(s, w);
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    long long e, s;
    cin >> s >> e;
    w[i] = chk(s, e);
    l[i] = lck(s, e);
  }
  bool f = 1, s = 0;
  for (int i = 1; i <= T; i++) {
    if (f == 1 && s == 1) break;
    if (f == 0 && s == 0) break;
    if (s == 1) {
      w[i] = 1 - w[i];
      l[i] = 1 - l[i];
    }
    s = w[i];
    f = l[i];
  }
  cout << s << ' ' << f;
  return 0;
}
