#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const long long INF = (long long)(1 << 30) * (1 << 30);
long long n, i1, i2, x, k1, k2, predict;
long long cnt, d;
long long head, tail;
int main() {
  scanf("%I64d", &n);
  head = 1, predict = d = INF;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (predict != INF) predict += d;
    if (predict <= 0) head = i, i1 = i2 = k1 = k2 = 0, d = predict = INF, cnt++;
    if (x != -1) {
      if (!i1) {
        i1 = i, k1 = x;
      } else if (!i2) {
        if ((x - k1) % (i - i1) == 0) {
          k2 = x, predict = k2, i2 = i;
          d = (k2 - k1) / (i2 - i1);
          if (k1 < k2) {
            if (k1 - d * (i1 - head) <= 0)
              cnt++, head = i1, i1 = i, k1 = x, i2 = k2 = 0, d = predict = INF;
          }
        } else {
          cnt++, head = i, i1 = i, k1 = x, i2 = k2 = 0, d = predict = INF;
        }
      } else {
        if (predict != x)
          head = i1 = i, k1 = x, i2 = k2 = 0, cnt++, d = predict = INF;
      }
    }
  }
  cnt++;
  cout << cnt;
  return 0;
}
