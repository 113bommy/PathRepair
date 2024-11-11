#include <bits/stdc++.h>
using namespace std;
int dem, n, k;
int a[101];
int t[1001];
int v[1001];
void run() {
  while ((*max_element(a, a + n) - *min_element(a, a + n) > 0) && (dem < k)) {
    t[dem] = max_element(a, a + n) - a + 1;
    v[dem] = min_element(a, a + n) - a + 1;
    a[t[dem] - 1]--;
    a[v[dem] - 1]++;
    dem++;
  }
}
int main() {
  dem = 0;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  run();
  printf("%d %d\n", *max_element(a, a + n) - *min_element(a, a + n), dem);
  for (int i = 0; i < dem; i++) printf("%d %d\n", t[i], v[i]);
}
