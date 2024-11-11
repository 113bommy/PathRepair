#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100100;
int n, a[MAXN];
int is1[20 * MAXN];
void f(int l, int r) {
  int t = (l + r) / 2;
  if (r - l < 2) {
    if (l == r)
      return;
    else {
      is1[a[l]] = 1;
      return;
    }
  } else {
    f(l, t);
    f(t, r);
    set<int> s1, s2;
    int tmp = 0;
    for (int i = t; i <= (r - 1); ++i) {
      tmp |= a[i];
      is1[tmp] = true;
      s2.insert(tmp);
    }
    tmp = 0;
    for (int i = t; i >= (l); --i) {
      tmp |= a[i];
      is1[tmp] = true;
      s1.insert(tmp);
    }
    for (__typeof((s1).begin()) it1 = ((s1).begin()); it1 != (s1).end();
         ++it1) {
      for (__typeof((s2).begin()) it2 = ((s2).begin()); it2 != (s2).end();
           ++it2) {
        is1[(*it1) | (*it2)] = 1;
      }
    }
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < (n); ++i) cin >> a[i];
  f(0, n);
  int res = 0;
  for (int i = 0; i < (20 * MAXN); ++i) {
    res += is1[i];
  }
  cout << res << endl;
}
