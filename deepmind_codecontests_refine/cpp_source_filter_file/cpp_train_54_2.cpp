#include <bits/stdc++.h>
using namespace std;
int maxx, maxy, w, ansx = -1, ansy = -1, sum[100100], cnt[100100], rev[100100];
map<int, int> divs;
int _rev(int x) {
  int res = 0;
  while (x) {
    res = 10 * res + x % 10;
    x /= 10;
  }
  return res;
}
void factor(int x, int c) {
  for (int i = 2; i * i <= x; i++)
    while (!(x % i)) {
      divs[i] += c;
      x /= i;
    }
  if (x > 1) divs[x] += c;
}
int get_sum(int y) {
  int res = 0;
  for (; y >= 0; y = (y & (y + 1)) - 1) res += sum[y];
  return res;
}
void change(int y) {
  for (; y <= maxy; y |= y + 1) sum[y]++;
}
int main() {
  int start = time(0);
  cin >> maxx >> maxy >> w;
  for (int i = 1; i <= max(maxx, maxy); i++) rev[i] = _rev(i);
  for (int x = 1; x <= maxx; x++) {
    divs.clear();
    int revx = rev[x];
    factor(x, 1);
    factor(revx, -1);
    int p1 = 1, p2 = 1;
    for (map<int, int>::iterator it = divs.begin(); it != divs.end(); it++) {
      for (int i = 0; i < (*it).second; i++) p1 *= (*it).first;
      for (int i = 0; i > (*it).second; i--) p2 *= (*it).first;
    }
    for (int y = p2; y <= maxy; y += p2) {
      int revy = rev[y];
      if (x * y == revx * revy) change(y);
    }
    int l = 1, r = maxy + 1, m;
    while (r - l > 1) {
      m = (l + r) >> 1;
      if (get_sum(m) < w)
        l = m;
      else
        r = m;
    }
    if (r <= maxy) {
      if (ansx == -1 || 1LL * ansx * ansy > 1LL * x * r) {
        ansx = x;
        ansy = r;
      }
    }
  }
  if (ansx == -1)
    cout << -1;
  else
    cout << ansx << " " << ansy;
  cerr << (time(0) - start);
  return 0;
}
