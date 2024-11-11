#include <bits/stdc++.h>
using namespace std;
struct n {
  int w;
  int h;
  int idx;
} f[200000];
struct n2 {
  int a;
  int idx;
} ar[200000];
bool cmp(struct n a, struct n b) { return a.h > b.h; }
bool cmp2(struct n2 a, struct n2 b) { return a.idx < b.idx; }
int main() {
  int t, i, sumw = 0;
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> f[i].w >> f[i].h;
    sumw += f[i].w;
    f[i].idx = i;
  }
  sort(f, f + t, cmp);
  for (i = t - 1; i > 0; i--) {
    ar[i].a = (sumw - f[i].w) * f[0].h;
    ar[i].idx = f[i].idx;
  }
  ar[0].a = (sumw - f[0].w) * f[1].h;
  ar[0].idx = f[0].idx;
  sort(ar, ar + t, cmp2);
  for (i = 0; i < t; i++) {
    cout << ar[i].a << " ";
  }
}
