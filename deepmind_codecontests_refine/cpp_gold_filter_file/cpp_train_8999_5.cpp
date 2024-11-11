#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const long long MAXVAL = 100000000000000ll;
const long long SQRTMAXVAL = 10000000ll;
const int SQRTMAXLEN = 7;
bool ok_up[SQRTMAXVAL];
bool ok_down[SQRTMAXVAL];
struct point {
  long long first, second;
  point() {}
  point(long long a, long long b) : first(a), second(b) {}
  const bool operator<(const point &B) const {
    return first < B.first || first == B.first && second < B.second;
  }
};
long long n, k;
int UpSize, DownSize;
point Up[377740 + 1], Down[377740 + 1];
int ValueSize;
pair<int, int> Value[1000000];
int length(long long x) {
  int r = 1;
  x /= 10;
  while (x) {
    r++;
    x /= 10;
  }
  return r;
}
int ok(long long x, int Length = -1) {
  if (Length < 0) Length = length(x);
  if (Length <= 1) return 3;
  long long vx = x / 10;
  int p1 = vx % 10, p2 = x % 10;
  int r = 0;
  if (ok_up[vx]) {
    if ((Length & 1) == 1 && p1 > p2) r |= 2;
    if ((Length & 1) == 0 && p1 < p2) r |= 2;
  }
  if (ok_down[vx]) {
    if ((Length & 1) == 1 && p1 < p2) r |= 1;
    if ((Length & 1) == 0 && p1 > p2) r |= 1;
  }
  return r;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  scanf("%I64d%I64d", &n, &k);
  for (int i = 0; i < SQRTMAXVAL; i++) {
    int Length = length(i), val = ok(i, Length);
    if (val & 1) ok_down[i] = true;
    if (val & 2) ok_up[i] = true;
    if (val && i) Value[ValueSize++] = make_pair(val, i);
    if (val & 1 && Length == SQRTMAXLEN) Down[DownSize++] = point(i % n, i);
    if (val & 2 && Length == SQRTMAXLEN) Up[UpSize++] = point(i % n, i);
    if (val & 1 && Length == SQRTMAXLEN - 1) Up[UpSize++] = point(i % n, i);
  }
  long long count = 0;
  for (int i = 0; i < ValueSize; i++) {
    if (Value[i].second % n) continue;
    count++;
    if (count == k) {
      printf("%I64d", Value[i].second);
      return 0;
    }
  }
  sort(Down, Down + DownSize);
  sort(Up, Up + UpSize);
  for (int id = 0; id < ValueSize; id++) {
    int i = Value[id].second;
    int ok_val = Value[id].first;
    int lx = i % 10;
    long long mod = (((-i * SQRTMAXVAL) % n) + n) % n;
    int n_ok = ok_val;
    if ((length(i) & 1) == 0) n_ok = ((ok_val & 1) << 1) | ((ok_val & 2) >> 1);
    long long value = 0;
    if (lx > 0 && (n_ok & 1)) {
      point *it_left, *it_right;
      it_left = lower_bound(Up, Up + UpSize, point(mod, 0ll));
      it_right = lower_bound(Up, Up + UpSize, point(mod, lx * SQRTMAXVAL / 10));
      value += it_right - it_left;
    }
    if (lx < 10 && (n_ok & 2)) {
      point *it_left, *it_right;
      it_left = lower_bound(Down, Down + DownSize,
                            point(mod, (lx + 1) * SQRTMAXVAL / 10));
      it_right = lower_bound(Down, Down + DownSize, point(mod + 1, 0ll));
      value += it_right - it_left;
    }
    if (count + value >= k) {
      printf("%d", i);
      point *it_left, *it_right;
      it_left = lower_bound(Up, Up + UpSize, point(mod, 0ll));
      it_right = lower_bound(Up, Up + UpSize, point(mod, lx * SQRTMAXVAL / 10));
      if (lx > 0 && (n_ok & 1)) {
        long long length1 = min(it_right - it_left + 0ll, k - count);
        count += length1;
        if (count == k) {
          printf("%07I64d", (it_left + (length1 - 1))->second);
          return 0;
        }
      }
      it_left = lower_bound(Down, Down + DownSize,
                            point(mod, (lx + 1) * SQRTMAXVAL / 10));
      it_right = lower_bound(Down, Down + DownSize, point(mod + 1, 0ll));
      if (lx < 10 && (n_ok & 2)) {
        long long length2 = min(it_right - it_left + 0ll, k - count);
        count += length2;
        if (count == k) {
          printf("%07I64d", (it_left + (length2 - 1))->second);
          return 0;
        }
      }
      printf("Ololo");
      return 0;
    }
    count += value;
  }
  printf("-1");
  return 0;
}
