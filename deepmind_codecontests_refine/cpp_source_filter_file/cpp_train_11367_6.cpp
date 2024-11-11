#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e13;
const double PI = acos(-1);
const long long M = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    long long k;
    cin >> k;
    long long lo = 1, hi = 21837, best;
    while (lo <= hi) {
      long long md = (lo + hi) / 2;
      long long res = 0, po = 1;
      while (po <= md) {
        res += ((md - po + 1) * (md - po + 1) + (md - po + 1)) / 2;
        po *= 10;
      }
      if (res >= k) {
        best = md;
        hi = md - 1;
      } else
        lo = md + 1;
    }
    best--;
    long long res = 0, po = 1;
    while (po <= best) {
      res += ((best - po + 1) * (best - po + 1) + (best - po + 1)) / 2;
      po *= 10;
    }
    k -= res;
    lo = 1, hi = best + 1;
    best = 0;
    while (lo <= hi) {
      long long md = (lo + hi) / 2;
      res = md, po = 10;
      while (po <= md) {
        res += (md - po + 1);
        po *= 10;
      }
      if (res >= k) {
        best = md;
        hi = md - 1;
      } else
        lo = md + 1;
    }
    best--;
    res = best, po = 10;
    while (po <= best) {
      res += (best - po + 1);
      po *= 10;
    }
    k -= res;
    po = 1;
    best++;
    while (po * 10 <= best) po *= 10;
    while (po) {
      k--;
      if (!k) {
        cout << (best / po) % 10 << endl;
        break;
      }
      po /= 10;
    }
  }
}
