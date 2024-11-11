#include <bits/stdc++.h>
using namespace std;
int n;
int a, b, c, d;
int p[5010];
int size[5010];
vector<int> e[5010];
bool v[5010];
bool ff(int x, int y) {
  memset(v, 0, sizeof(v));
  bitset<5010> w;
  w.reset();
  w[0] = 1;
  int a, b;
  a = x;
  b = y;
  while (p[a] > 1) a = p[a];
  while (p[b] > 1) b = p[b];
  v[a] = 1;
  v[b] = 1;
  for (int i = x; i != 0; i = p[i]) {
    v[i] = 1;
    for (auto &j : e[i]) {
      if (!v[j]) w |= w << size[j];
    }
  }
  for (int i = y; i != 1; i = p[i]) {
    v[i] = 1;
    for (auto &j : e[i]) {
      if (!v[j]) w |= w << size[j];
    }
  }
  return w[size[1] / 2 - 1];
}
int main() {
  scanf("%d", &n);
  scanf("%d%d%d%d", &a, &b, &c, &d);
  for (int i = 2; i <= n; i++) {
    scanf("%d", &p[i]);
    e[p[i]].push_back(i);
  }
  for (int i = n; i >= 1; i--) {
    size[i] = max(size[i], 1);
    size[p[i]] += size[i];
  }
  if (size[1] & 1) {
    puts("NO");
    return 0;
  }
  if (ff(a, b) && ff(c, d))
    puts("YES");
  else
    puts("NO");
  return 0;
}
