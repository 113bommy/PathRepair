#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 4;
int n, a[MAXN], cnt[2 * MAXN], lmin[MAXN], lmax[MAXN], rmin[MAXN], rmax[MAXN];
long long int sol = 0;
vector<int> obris;
bool ui(int x, int l, int r) { return (x >= l && x <= r); }
void rek(int s, int e) {
  if (s == e) {
    sol++;
    return;
  }
  int mid = (s + e) / 2;
  rmin[mid + 1] = a[mid + 1];
  rmax[mid + 1] = a[mid + 1];
  for (int i = mid + 2; i <= e; i++) rmin[i] = min(rmin[i - 1], a[i]);
  for (int i = mid + 2; i <= e; i++) rmax[i] = max(rmax[i - 1], a[i]);
  lmin[mid] = a[mid];
  lmax[mid] = a[mid];
  for (int i = mid - 1; i >= s; i--) lmin[i] = min(lmin[i + 1], a[i]);
  for (int i = mid - 1; i >= s; i--) lmax[i] = max(lmax[i + 1], a[i]);
  for (int i = s; i <= mid; i++) {
    int z = lmax[i] - lmin[i], nr = i + z;
    if (ui(nr, mid + 1, e)) {
      if (rmax[nr] < lmax[i] && rmin[nr] > lmin[i]) {
        sol++;
      }
    }
  }
  for (int i = e; i > mid; i--) {
    int z = rmax[i] - rmin[i], nl = i - z;
    if (z > 0 && ui(nl, s, mid)) {
      if (lmax[nl] < rmax[i] && lmin[nl] > rmin[i]) {
        sol++;
      }
    }
  }
  int l = e + 1, r = e + 1;
  for (int i = s; i <= mid; i++) {
    while (l > mid + 1 && rmin[l - 1] < lmin[i]) {
      cnt[l - 1 + rmin[l - 1]]++;
      l--;
    }
    while (r > l && (rmax[r - 1] > lmax[i] || lmin[i] < rmin[r - 1])) {
      cnt[r - 1 + rmin[r - 1]]--;
      r--;
    }
    sol += cnt[lmax[i] + i];
  }
  while (r > l) {
    cnt[r - 1 + rmin[r - 1]] = 0;
    r--;
  }
  l = e + 1;
  r = e + 1;
  for (int i = s; i <= mid; i++) {
    while (l > mid + 1 && rmax[l - 1] > lmax[i]) {
      cnt[rmax[l - 1] - l + 1 + MAXN]++;
      l--;
    }
    while (r > l && (rmax[r - 1] < lmax[i] || rmin[r - 1] < lmin[i])) {
      cnt[rmax[r - 1] - r + 1 + MAXN]--;
      r--;
    }
    sol += cnt[lmin[i] - i + MAXN];
  }
  while (r > l) {
    cnt[rmax[r - 1] - r + 1 + MAXN] = 0;
    r--;
  }
  rek(s, mid);
  rek(mid + 1, e);
}
int main() {
  int ri, ci;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ri >> ci;
    ri--;
    ci--;
    a[ci] = ri;
  }
  rek(0, n - 1);
  cout << sol;
  return 0;
}
