#include <bits/stdc++.h>
using namespace std;
const int MAX = (1 << 23);
const int OFFSET = 4004000;
struct BIT {
  int bit[MAX];
  void init() {
    for (int i = 0; i < MAX; i++) bit[i] = 0;
  }
  BIT() { init(); }
  void insert(int v, int i) {
    i += OFFSET;
    for (; i < MAX; i += i & -i) bit[i] += v;
  }
  int lookup(int i) {
    int res = 0;
    i += OFFSET;
    for (; i > 0; i -= i & -i) res += bit[i];
    return res;
  }
  int lookup(int l, int r) { return lookup(r) - lookup(l - 1); }
};
struct HSeg {
  int x, y;
};
struct VSeg {
  int x, y;
};
bool cmph(HSeg a, HSeg b) {
  if (a.y < b.y) return true;
  if (a.y > b.y) return false;
  if (a.x < b.x) return true;
  return false;
}
bool cmpv(VSeg a, VSeg b) {
  if (a.x < b.x) return true;
  if (a.x > b.x) return false;
  if (a.y < b.y) return true;
  return false;
}
void get(int& x, int& y) {
  int x2, y2;
  cin >> x2 >> y2;
  x = x2 - y2;
  y = x2 + y2;
}
int nH, nV;
HSeg H[2020];
VSeg V[2020];
BIT bit;
struct endV {
  int x, y, t;
};
bool cmpvy(endV a, endV b) {
  if (a.y < b.y) return true;
  if (a.y > b.y) return false;
}
endV temp[4040];
struct HSeg2 {
  int xl, xr, y;
};
HSeg2 mergedH[4040];
struct VSeg2 {
  int x, yl, yr;
};
VSeg2 mergedV[4040];
bool test(int t) {
  int nH2 = 0;
  for (int i = 0; i < nH; i++) {
    if (i > 0 && H[i].y == H[i - 1].y && H[i].x - H[i - 1].x <= 4 * t)
      mergedH[nH2 - 1].xr = H[i].x + 2 * t;
    else {
      mergedH[nH2].y = H[i].y;
      mergedH[nH2].xl = H[i].x - 2 * t;
      mergedH[nH2].xr = H[i].x + 2 * t;
      nH2++;
    }
  }
  int nV2 = 0;
  for (int i = 0; i < nV; i++) {
    if (i > 0 && V[i].x == V[i - 1].x && V[i].y - V[i - 1].y <= 4 * t) {
      mergedV[nV2 - 1].yr = V[i].y + 2 * t;
    } else {
      mergedV[nV2].x = V[i].x;
      mergedV[nV2].yl = V[i].y - 2 * t;
      mergedV[nV2].yr = V[i].y + 2 * t;
      nV2++;
    }
  }
  bool good = false;
  for (int fix = 0; fix < nH2; fix++) {
    int next = 0;
    for (int vi = 0; vi < nV2; vi++) {
      if (mergedH[fix].xl <= mergedV[vi].x &&
          mergedV[vi].x <= mergedH[fix].xr &&
          mergedV[vi].yl <= mergedH[fix].y &&
          mergedH[fix].y <= mergedV[vi].yr) {
        temp[next].x = mergedV[vi].x;
        temp[next].y = mergedV[vi].yl;
        temp[next].t = 1;
        next++;
        temp[next].x = mergedV[vi].x;
        temp[next].y = mergedV[vi].yr;
        temp[next].t = -1;
        next++;
      }
    }
    sort(temp, temp + next, cmpvy);
    int vi = 0;
    for (int hi = 0; hi < nH2; hi++) {
      while (vi < next && temp[vi].y <= mergedH[hi].y) {
        bit.insert(temp[vi].t, temp[vi].x);
        vi++;
      }
      if (mergedH[hi].y != mergedH[fix].y &&
          bit.lookup(mergedH[hi].xl, mergedH[hi].xr) >= 2)
        good = true;
    }
    while (vi < next) {
      bit.insert(temp[vi].t, temp[vi].x);
      vi++;
    }
    if (good) break;
  }
  return good;
}
int main() {
  cin >> nH >> nV;
  for (int i = 0; i < nH; i++) {
    get(H[i].x, H[i].y);
  }
  for (int i = 0; i < nV; i++) {
    get(V[i].x, V[i].y);
  }
  sort(H, H + nH, cmph);
  sort(V, V + nV, cmpv);
  int low = 0, high = 1000010;
  while (low + 1 < high) {
    int mid = (low + high) / 2;
    if (test(mid))
      high = mid;
    else
      low = mid;
  }
  if (high == 1000010)
    cout << "Poor Sereja!\n";
  else
    cout << high << endl;
  return 0;
}
