#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
bool w[N], l[N];
bool get_win(long long s, long long e) {
  if (e & 1) {
    return !(s & 1);
  }
  if (s > e / 2) {
    return ((s ^ e) & 1);
  }
  if (s > e / 4) {
    return 1;
  }
  return get_win(s, e / 4);
}
bool get_lose(long long s, long long e) {
  if (s > e / 2) {
    return 1;
  }
  return get_win(s, e / 2);
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    long long s, e;
    cin >> s >> e;
    w[i] = get_win(s, e);
    l[i] = get_lose(s, e);
  }
  bool res1 = w[t - 1], res2 = l[t - 1];
  for (int i = t - 2; i >= 0; --i) {
    res1 = res1 ? l[i] : w[i];
    res2 = res2 ? l[i] : w[i];
  }
  cout << res1 << ' ' << res2 << endl;
  return 0;
}
