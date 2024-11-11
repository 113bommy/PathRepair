#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;
int n;
int v[N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  sort(v, v + n);
  for (int i = 2; i < n; i += 2) swap(v[i], v[i - 1]);
  for (int i = 0; i < n; i++) printf("%d ", v[i]);
  printf("\n");
  return 0;
}
