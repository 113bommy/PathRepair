#include <bits/stdc++.h>
struct drift {
  int x, y;
  bool v;
  drift(int a, int b) : x(a), y(b), v(0){};
};
std::vector<drift> V;
void search(int start, int L) {
  if (V[start].v == 1) {
    return;
  }
  V[start].v = 1;
  for (int p = 0; p < L; p++) {
    if (V[p].x == V[start].x || V[p].y == V[start].y) {
      search(p, L);
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int p = 0; p < n; p++) {
    int f, g;
    scanf("%d %d", &f, &g);
    V.push_back(drift(f, g));
  }
  int components = 0;
  for (int p = 0; p < n; p++) {
    if (V[p].v > 0) {
      continue;
    }
    ++components;
    search(n, p);
  }
  printf("%d\n", components - 1);
  return 0;
}
