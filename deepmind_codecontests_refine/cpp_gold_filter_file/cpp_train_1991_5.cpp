#include <bits/stdc++.h>
using namespace std;
const int maxn = 212345;
int n, C[3][maxn], q;
set<int> s[3];
char ini[maxn], op[5];
inline int lowbit(int x) { return x & -x; }
int sum(const int *C, int x) {
  int ret = 0;
  while (x > 0) {
    ret += C[x];
    x -= lowbit(x);
  }
  return ret;
}
void add(int *C, int x, int d) {
  while (x <= n) {
    C[x] += d;
    x += lowbit(x);
  }
}
int query() {
  int cnt = 0;
  for (int(i) = (0); (i) <= ((3) - 1); (i)++) cnt += s[i].empty();
  if (cnt == 2) return n;
  if (cnt == 1)
    for (int(i) = (0); (i) <= ((3) - 1); (i)++)
      if (s[i].size() && s[(i + 2) % 3].size()) return s[i].size();
  int ans = n;
  for (int(i) = (0); (i) <= ((3) - 1); (i)++) {
    int l = *(s[(i + 1) % 3].begin()), r = *(s[(i + 2) % 3].begin());
    if (r > l) ans -= sum(C[i], r) - sum(C[i], l);
    l = *(s[(i + 2) % 3].rbegin()), r = *(s[(i + 1) % 3].rbegin());
    if (r > l) ans -= sum(C[i], r) - sum(C[i], l);
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &q);
  scanf("%s", ini + 1);
  for (int(i) = (1); (i) <= (n); (i)++) {
    if (ini[i] == 'R') {
      add(C[0], i, 1);
      s[0].insert(i);
    } else if (ini[i] == 'P') {
      add(C[1], i, 1);
      s[1].insert(i);
    } else {
      add(C[2], i, 1);
      s[2].insert(i);
    }
  }
  printf("%d\n", query());
  while (q--) {
    int i;
    scanf("%d%s", &i, op);
    if (ini[i] == 'R') {
      add(C[0], i, -1);
      s[0].erase(i);
    } else if (ini[i] == 'P') {
      add(C[1], i, -1);
      s[1].erase(i);
    } else {
      add(C[2], i, -1);
      s[2].erase(i);
    }
    ini[i] = op[0];
    if (ini[i] == 'R') {
      add(C[0], i, 1);
      s[0].insert(i);
    } else if (ini[i] == 'P') {
      add(C[1], i, 1);
      s[1].insert(i);
    } else {
      add(C[2], i, 1);
      s[2].insert(i);
    }
    printf("%d\n", query());
  }
}
