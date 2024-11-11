#include <bits/stdc++.h>
int* array;
int f(int index) {
  if (array[index] == -1) {
    array[index] = index;
    return index;
  }
  if (array[index] == index) return index;
  int r = f(array[index]);
  array[index] = r;
  return r;
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int coils = 0;
  int connect[n];
  array = connect + 0;
  int notcoils[n];
  for (int i = 0; i < n; i++) {
    connect[i] = i;
    notcoils[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int b, e;
    scanf("%d %d", &b, &e);
    --b;
    --e;
    if (b == e) {
      if (connect[b] == -1) connect[b] = b;
      ++coils;
    } else {
      int rootb = f(b);
      int roote = f(e);
      connect[roote] = rootb;
      ++notcoils[b];
      ++notcoils[e];
    }
  }
  int notcoilsTotal = m - coils;
  int r = -1;
  for (int i = 0; i < n; i++) {
    if (connect[i] != -1)
      if (f(i) != r) {
        if (r == -1)
          r = connect[i];
        else {
          printf("%d", 0);
          return 0;
        }
      }
  }
  long long ans = coils;
  ans = ans * (ans - 1) / 2 + notcoilsTotal * ans;
  for (int i = 0; i < n; i++) {
    long long nc = notcoils[i];
    ans += nc * (nc - 1) / 2;
  }
  std::cout << ans;
  return 0;
}
