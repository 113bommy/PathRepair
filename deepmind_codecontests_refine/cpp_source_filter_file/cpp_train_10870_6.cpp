#include <bits/stdc++.h>
using namespace std;
long long cnt[21], p[21];
long long w, m, k;
void initcnt() {
  for (int i = 1; i < 21; i++) {
    cnt[i] = i == 1 ? 9 : (cnt[i - 1] * 10ll);
    p[i] = i == 1 ? 10 : (p[i - 1] * 10ll);
  }
}
int s(long long num) {
  int res = 0;
  while (num) {
    num /= 10ll;
    res++;
  }
  return res;
}
long long solv() {
  int bit = s(m);
  long long res = 0;
  long long a = p[bit];
  long long dif = (a - m);
  if (dif * (long long)bit >= w) {
    return w / k;
  }
  res += dif;
  w -= dif * (long long)bit;
  bit++;
  while (w - cnt[bit] * bit >= 0) {
    w -= cnt[bit] * bit;
    res += cnt[bit];
    bit++;
  }
  res += w / bit;
  return res;
}
int main() {
  initcnt();
  cin >> w >> m >> k;
  w /= k;
  cout << solv() << endl;
  return 0;
}
