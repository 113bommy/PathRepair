#include <bits/stdc++.h>
using namespace std;
int H, W;
long double ans;
long long w, h;
void findw(long long h1) {
  long double l = 0.8;
  long double r = 100.0;
  long double m;
  while (r - l > 1e-10) {
    m = (l + r) / 2;
    if (floor(h1 / m) <= W)
      r = m;
    else
      l = m;
  }
  long double R;
  if (floor(h1 / r) <= W)
    R = r;
  else
    R = l;
  if (h1 * floor(h1 / R) > ans && floor(h1 / R) <= W &&
      (h1 / floor(h1 / R) - 0.8 >= 1e-2 && h1 / floor(h1 / R) - 1.25 <= 1e-2)) {
    ans = h1 * floor(h1 / R);
    h = h1;
    w = floor(h1 / R);
  }
  if (h1 * ceil(h1 / R) > ans && ceil(h1 / R) <= W &&
      (h1 / ceil(h1 / R) - 0.8 <= 1e-2 && h1 / ceil(h1 / R) - 1.25 <= 1e-2)) {
    ans = h1 * ceil(h1 / R);
    h = h1;
    w = ceil(h1 / R);
  }
}
void findh(long long w1) {
  long double l = 0.8;
  long double r = 10.0;
  long double m;
  while (r - l > 1e-10) {
    m = (l + r) / 2;
    if (floor(w1 * m) <= H)
      l = m;
    else
      r = m;
  }
  long double R;
  if (floor(w1 * r) <= H)
    R = r;
  else
    R = l;
  if (w1 * floor(w1 * R) > ans && floor(w1 * R) <= H &&
      (floor(w1 * R) / w1 - 0.8 >= 1e-2 && floor(w1 * R) / w1 - 1.25 <= 1e-2)) {
    ans = w1 * floor(w1 * R);
    h = floor(w1 * R);
    w = w1;
  }
  if (w1 * ceil(w1 * R) > ans && ceil(w1 * R) <= H &&
      (ceil(w1 * R) / w1 - 0.8 <= 1e-2 && ceil(w1 * R) / w1 - 1.25 <= 1e-2)) {
    ans = w1 * ceil(w1 * R);
    h = ceil(w1 * R);
    w = w1;
  }
}
int main() {
  cin >> H >> W;
  for (int i = 0; (1 << i) <= H; ++i) {
    long double a = (1 << i);
    findw(a);
  }
  for (int i = 0; (1 << i) <= W; ++i) {
    long double a = (1 << i);
    findh(a);
  }
  if (h <= W && w <= H && h < w) swap(h, w);
  cout << h << " " << w << endl;
}
