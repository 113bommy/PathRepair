#include <bits/stdc++.h>
using namespace std;
const int inf = 3000009;
int pos[inf];
bool st[inf];
int tree[inf];
int num[inf];
void update(int a, int v) {
  if (!a) return;
  for (; a < inf; a += a & -a) tree[a] += v;
}
int query(int a) {
  int x = 0;
  for (; a; a -= a & -a) x += tree[a];
  return x;
}
int main() {
  int n, m, a, b, c;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &num[i]);
    pos[num[i]] = i;
  }
  pos[n + 1] = n + 3;
  for (int i = 1; i < n; ++i)
    if (pos[i] > pos[i + 1]) update(i, 1), st[i] = true;
  scanf("%d", &m);
  bool is;
  while (m--) {
    scanf("%d%d%d", &c, &a, &b);
    if (c == 1)
      printf("%d\n", query(b - 1) - query(a - 1) + 1);
    else {
      swap(num[a], num[b]);
      a = num[a], b = num[b];
      swap(pos[a], pos[b]);
      is = pos[a + 1] < pos[a];
      if (is != st[a]) update(a, is ? 1 : -1);
      st[a] = is;
      is = pos[b + 1] < pos[b];
      if (is != st[b]) update(b, is ? 1 : -1);
      st[b] = is;
      is = pos[b] < pos[b - 1];
      if (is != st[b - 1]) update(b - 1, is ? 1 : -1);
      st[b - 1] = is;
      is = pos[a] < pos[a - 1];
      if (is != st[a - 1]) update(a - 1, is ? 1 : -1);
      st[a - 1] = is;
    }
  }
}
