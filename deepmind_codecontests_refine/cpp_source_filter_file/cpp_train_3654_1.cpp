#include <bits/stdc++.h>
using namespace std;
map<int, int> freq;
map<int, int>::iterator it, it2;
int f[10100], val[10100];
int main() {
  double melhorV, l1, l2, p, s;
  int v, noCases, ans1, n, ans2, po, a1, a2, d, melhorD, fra1, fra2;
  scanf("%d", &noCases);
  while (noCases--) {
    freq.clear();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &v);
      if (freq.count(v) == 0)
        freq[v] = 1;
      else
        freq[v]++;
    }
    po = 0;
    for (it = freq.begin(); it != freq.end(); ++it) {
      a1 = (*it).first;
      fra1 = (*it).second;
      if (fra1 > 1) {
        val[po] = a1;
        f[po++] = fra1;
      }
    }
    melhorV = 2e9;
    melhorD = 2e9;
    ans1 = ans2 = -1;
    for (int i = 0; i < po; i++) {
      a1 = val[i];
      fra1 = f[i];
      if (fra1 >= 4) {
        ans1 = a1;
        ans2 = a1;
        break;
      }
      if (i == p - 1) break;
      a2 = val[i + 1];
      fra2 = f[i + 1];
      if (fra2 >= 4) {
        ans1 = a2;
        ans2 = a2;
        break;
      }
      if (fra1 >= 2 and fra2 >= 2) {
        l1 = a1;
        l2 = a2;
        p = l1 * 2 + l2 * 2;
        p *= p;
        s = l1 * l2;
        p /= s;
        if (p < melhorV) {
          melhorV = p;
          ans1 = a1;
          ans2 = a2;
        }
      }
    }
    assert(ans1 != -1 and ans2 != -1);
    printf("%d %d %d %d\n", ans1, ans1, ans2, ans2);
  }
  return 0;
}
