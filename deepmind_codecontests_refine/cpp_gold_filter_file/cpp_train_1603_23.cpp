#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:167177216")
using namespace std;
struct otr {
  int a, b, c;
};
bool cmp(otr &a, otr &b) {
  if (a.a != b.a) return a.a < b.a;
  if (a.b != b.b) return a.b > b.b;
  return a.c < b.c;
}
int main() {
  int n, m;
  scanf("%d%d", &m, &n);
  vector<otr> v(n);
  for (int i = 0; i < int(n); ++i) {
    scanf("%d%d", &v[i].a, &v[i].b);
    v[i].b += v[i].a - 1;
    v[i].c = i;
  }
  sort(v.begin(), v.end(), cmp);
  vector<int> ans;
  int maxr = -1, l = 0, r = 0;
  int pos = 0, last = 0;
  while (l < n) {
    if (v[l].a > maxr) {
      last = l;
      maxr = v[l].b;
    }
    int nmaxr = maxr;
    while (r < n && v[r].a <= maxr + 1) {
      if (v[r].b > nmaxr) {
        nmaxr = v[r].b;
        pos = r;
      }
      r++;
    }
    while (l < r) {
      if (pos != l && last != l) ans.push_back(v[l].c);
      l++;
    }
    maxr = nmaxr;
  }
  cout << ans.size() << endl;
  for (int i = 0; i < int(ans.size()); ++i) cout << ans[i] + 1 << ' ';
  return 0;
}
