#include <bits/stdc++.h>
using namespace std;
int INF = 999999999;
double EPSILON = 0.00000001;
int factorize(int w, int h, int p) {
  bool swapped = false;
  if (w > h) {
    swap(h, w);
    swapped = true;
  }
  for (int wc = ((1) > (p / h) ? (1) : (p / h)); wc <= w and wc * wc <= p;
       wc++) {
    if (p % wc == 0) {
      int hd = p / wc;
      if (hd <= h) {
        if (swapped)
          return hd;
        else
          return wc;
      }
    }
  }
  return -1;
}
int main() {
  int maxh, maxw, s;
  cin >> maxh >> maxw >> s;
  if (s % 2 == 0) {
    cout << "0\n";
    return 0;
  }
  long long total = 0;
  for (int h = 1; h <= maxh; h += 2) {
    for (int w = 1; w <= maxw; w += 2) {
      if (h * w < s) continue;
      if ((h * w - s) % 4 != 0) continue;
      int p = (h * w - s) / 4;
      if (p > 0 and w == 1 or h == 1) continue;
      if (p > 0) {
        int ho2 = h / 2, wo2 = w / 2;
        for (int wc = ((1) > (p / ho2) ? (1) : (p / ho2)); wc <= wo2; wc++) {
          if (p % wc == 0) {
            int hd = p / wc;
            if (hd <= ho2) {
              int a = w, c = w - 2 * wc;
              int d = h, b = h - 2 * hd;
              int wcells = maxw - w + 1;
              int hcells = maxh - h + 1;
              long long z = wcells * hcells;
              int cur = z;
              if (a != c or b != d) cur += z;
              total += cur;
            }
          }
        }
      } else if (p == 0) {
        int wcells = maxw - w + 1;
        int hcells = maxh - h + 1;
        total += 1LL * wcells * hcells * ((h / 2 + 1) * (w / 2 + 1) * 2 - 1);
      }
    }
  }
  cout << total << endl;
  return 0;
}
