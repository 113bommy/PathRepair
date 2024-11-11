#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9 + 1;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  long long ans = 0;
  cin >> n;
  long long ber_max = 0, byt_max = 0, first_ber = INF, first_byt = INF;
  long long last_byt = INF, last_ber = INF, last_dis = INF;
  while (n--) {
    long long pos;
    char c;
    cin >> pos >> c;
    if (c == 'P') {
      if (last_dis == INF) {
        if (first_byt != INF) ans += pos - first_byt;
        if (first_ber != INF) ans += pos - first_ber;
        last_dis = pos;
        ber_max = byt_max = 0;
        last_byt = last_ber = INF;
        continue;
      }
      if (last_byt != INF) {
        byt_max = max(byt_max, pos - last_byt);
      }
      if (last_ber != INF) {
        ber_max = max(ber_max, pos - last_ber);
      }
      if (last_byt == INF) byt_max = pos - last_dis;
      if (last_ber == INF) ber_max = pos - last_dis;
      ans +=
          min(3LL * (pos - last_dis) - ber_max - byt_max, 2 * (pos - last_dis));
      last_byt = INF;
      last_ber = INF;
      last_dis = pos;
      ber_max = byt_max = 0;
    }
    if (c == 'R') {
      if (first_ber == INF) first_ber = pos;
      if (last_ber != INF) {
        ber_max = max(ber_max, pos - last_ber);
      } else if (last_dis != INF)
        ber_max = pos - last_dis;
      last_ber = pos;
    }
    if (c == 'B') {
      if (first_byt == INF) first_byt = pos;
      if (last_byt != INF) {
        byt_max = max(byt_max, pos - last_byt);
      } else if (last_dis != INF)
        byt_max = pos - last_dis;
      last_byt = pos;
    }
  }
  if (last_dis != INF) {
    if (last_byt != INF) ans += last_byt - last_dis;
    if (last_ber != INF) ans += last_ber - last_dis;
  } else {
    if (last_byt != INF) ans += last_byt - first_byt;
    if (last_ber != INF) ans += last_ber - first_ber;
  }
  cout << ans << '\n';
  return 0;
}
