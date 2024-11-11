#include <bits/stdc++.h>
using namespace std;
const int N = 102;
int n;
int v[N];
bool used[N];
bool cmp(int a, int b) { return a > b; }
int main(void) {
  scanf("%d", &n);
  for (int(i) = (0); (i) < (n); ++(i)) {
    scanf("%d", &v[i]);
  }
  sort(v, v + n, cmp);
  int res = 0, cnt = 0;
  while (cnt < n) {
    for (int(i) = (0); (i) < (n); ++(i)) {
      if (!used[i]) {
        res++;
        used[i] = 1;
        cnt++;
        int tam = 0, cap = v[i];
        for (int j = n - 1; j > i and tam <= cap and cap > 0; j--) {
          if (!used[j] and v[j] >= tam) {
            used[j] = 1;
            cnt++;
            tam++;
          }
        }
      }
    }
  }
  printf("%d\n", res);
  return 0;
}
