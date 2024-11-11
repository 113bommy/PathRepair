#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
void __never(int a) { printf("\nOPS %d", a); }
int n, k, q;
int p[128], pp[128];
set<int> Set;
int main() {
  cin >> n >> k;
  int kk = k;
  k = n / k;
  for (int a = (1); a <= (n); a++) cin >> p[a];
  double mi = 100500., ma = -1.;
  cin >> q;
  for (int a = (1); a <= (q); a++) {
    double sum = 0.;
    int x;
    for (int b = (1); b <= (k); b++) {
      cin >> x;
      Set.insert(x);
      sum += p[x];
    }
    sum /= k;
    mi = min(sum, mi);
    ma = max(sum, ma);
  }
  int i = 0;
  for (int a = (1); a <= (n); a++)
    if (Set.find(a) == Set.end()) pp[i++] = p[a];
  sort(pp, pp + i);
  if (i >= k && i > n - k * kk) {
    double s1 = 0., s2 = 0.;
    for (int a = (0); a <= (k - 1); a++) s1 += pp[a];
    for (int a = (i - k); a <= (i - 1); a++) s2 += pp[a];
    mi = min(mi, s1 / k);
    ma = max(ma, s2 / k);
  }
  printf("%.9lf %.9lf", mi, ma);
  return 0;
}
