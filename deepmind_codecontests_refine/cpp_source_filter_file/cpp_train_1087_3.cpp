#include <bits/stdc++.h>
using namespace std;
bool desc(int a, int b) { return a > b; }
int ok, ok1;
int v[105];
int f[105];
int main() {
  int n, pos = 0, p = 0, x;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x);
    v[++p] = x;
  }
  if (n == 1) {
    printf("%d", v[1]);
    return 0;
  }
  n = p;
  sort(v + 1, v + n + 1, desc);
  if (v[1] == 0) {
    printf("0");
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    if (v[i] > 0) {
      printf("%d ", v[i]);
      ok = 1;
    } else {
      break;
      pos = i;
    }
  }
  for (int i = n; i >= 1; --i) {
    if (v[i] < 0) {
      ok1 = 1;
    } else {
      pos = i;
      break;
    }
  }
  pos++;
  if ((n - pos + 1) % 2) pos++;
  for (int i = n; i >= pos; --i) printf("%d ", v[i]);
  if (!ok && !ok1) printf("%d", 0);
  return 0;
}
