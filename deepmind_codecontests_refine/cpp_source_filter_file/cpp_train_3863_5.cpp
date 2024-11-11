#include <bits/stdc++.h>
using namespace std;
struct nw {
  int l, r;
};
bool funcsort(nw a, nw b) {
  if (a.r < b.r || (a.r == b.r && a.l < b.l))
    return true;
  else
    return false;
}
nw a[200000];
int f[200000] = {0};
int c, i, j, n, m, l, r, ll, rr, rans;
vector<int> u;
void add(int x, int d) {
  while (x < u.size()) {
    f[x] = (f[x] + d) % 1000000007;
    x = x | (x + 1);
  }
}
int as(int x) {
  int ff = 0;
  while (x >= 0) {
    ff = (ff + f[x]) % 1000000007;
    x = (x & (x + 1)) - 1;
  }
  return ff;
}
int get(int ll, int rr) {
  return (as(rr) - as(ll - 1) + 1000000007) % 1000000007;
}
int main() {
  cin >> n >> m;
  u.push_back(0);
  map<int, int> ft;
  for (i = 0; i < m; ++i) {
    cin >> ll >> rr;
    a[i].l = ll;
    a[i].r = rr;
    ft[rr]++;
    if (ft[rr] == 1) u.push_back(rr);
  }
  sort(a, a + m, funcsort);
  sort(u.begin(), u.end());
  add(0, 1);
  for (i = 0; i < m; ++i) {
    if (i == 0) {
      rans = 0;
      ll = a[i].l;
      rr = a[i].r - 1;
      l = 0;
      r = u.size() - 1;
      while (l + 1 < r) {
        c = (l + r) / 2;
        if (u[c] >= ll)
          r = c;
        else
          l = c;
      }
      if (u[r] <= ll) l = r;
      ll = l;
      l = 0;
      r = u.size() - 1;
      while (l + 1 < r) {
        c = (l + r) / 2;
        if (u[c] <= rr)
          l = c;
        else
          r = c;
      }
      if (u[l] == rr) r = l;
      rr = r;
      rans = rans + get(ll, rr);
      rans = rans % 1000000007;
    } else {
      if (a[i].r != a[i - 1].r) {
        l = 0;
        r = u.size() - 1;
        while (l + 1 < r) {
          c = (l + r) / 2;
          if (u[c] > a[i - 1].r)
            r = c;
          else
            l = c;
        }
        if (u[r] <= a[i - 1].r) l = r;
        add(l, rans);
        rans = 0;
      }
      ll = a[i].l;
      rr = a[i].r - 1;
      l = 0;
      r = u.size() - 1;
      while (l + 1 < r) {
        c = (l + r) / 2;
        if (u[c] > ll)
          r = c;
        else
          l = c;
      }
      if (u[r] <= ll) l = r;
      ll = l;
      l = 0;
      r = u.size() - 1;
      while (l + 1 < r) {
        c = (l + r) / 2;
        if (u[c] < rr)
          l = c;
        else
          r = c;
      }
      if (u[l] == rr) r = l;
      rr = r;
      rans = rans + get(ll, rr);
      rans = rans % 1000000007;
    }
  }
  if (u[u.size() - 1] != n) rans = 0;
  cout << rans << endl;
}
