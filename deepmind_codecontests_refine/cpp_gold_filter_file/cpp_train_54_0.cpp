#include <bits/stdc++.h>
using namespace std;
double a[100010], b[100010], rev[100010];
multimap<double, int> xmap, ymap;
multimap<double, int>::iterator xit[100010], yit[100010];
int mx, my, w;
int main(int argc, char** argv) {
  cin >> mx >> my >> w;
  for (int i = 1; i <= max(mx, my); i++) {
    rev[i] = 0;
    int k = i;
    while (k) {
      rev[i] = rev[i] * 10 + k % 10;
      k /= 10;
    }
    a[i] = (double)i / rev[i];
    b[i] = (double)rev[i] / i;
    if (i <= mx) xit[i] = xmap.insert(make_pair(a[i], i));
  }
  int cnt = 0;
  int rx, ry, rt = -1;
  for (int i = 1, j = mx; i <= my; i++) {
    cnt += xmap.count(b[i]);
    yit[i] = ymap.insert(make_pair(b[i], i));
    while (cnt >= w) {
      if (rt == -1 || i * j < rt) {
        rt = i * j;
        rx = j;
        ry = i;
      }
      cnt -= ymap.count(a[j]);
      xmap.erase(xit[j]);
      j -= 1;
    }
  }
  if (rt == -1)
    cout << rt << endl;
  else
    cout << rx << " " << ry << endl;
  return (EXIT_SUCCESS);
}
