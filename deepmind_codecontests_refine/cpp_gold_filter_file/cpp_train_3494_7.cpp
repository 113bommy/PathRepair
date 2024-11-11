#include <bits/stdc++.h>
using namespace std;
void In() { freopen("in.in", "r", stdin); }
void Out() { freopen("out.out", "w", stdout); }
const int N = 1e5 + 10;
const int M = 3e5 + 10;
const int Mbit = 1e6 + 10;
const int inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
struct node {
  int a, b, c, id;
  bool operator<(const node &rhs) const {
    if (a != rhs.a) return a < rhs.a;
    if (b != rhs.b) return b < rhs.b;
    return c < rhs.c;
  }
} tmp[N];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    int ans = 0, id = 0;
    for (int i = 0; i < n; i++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      if (a < b) swap(a, b);
      if (b < c) swap(b, c);
      if (a < b) swap(a, b);
      tmp[i].a = a;
      tmp[i].b = b;
      tmp[i].c = c;
      tmp[i].id = i + 1;
      if (tmp[i].c > ans) ans = tmp[i].c, id = i + 1;
    }
    sort(tmp, tmp + n);
    int l = 0, r = 0, id1 = 0, id2 = 0;
    while (1) {
      r = l;
      if (l == n) break;
      while (tmp[r].a == tmp[l].a && tmp[r].b == tmp[l].b && r < n) r++;
      r--;
      if (l == r) {
        l = r + 1;
        continue;
      } else {
        int x = min(tmp[r].a, tmp[r].b);
        x = min(x, tmp[r].c + tmp[r - 1].c);
        if (x > ans) ans = x, id1 = tmp[r].id, id2 = tmp[r - 1].id;
        l = r + 1;
      }
    }
    if (id1 && id2)
      printf("2\n%d %d\n", id1, id2);
    else
      printf("1\n%d\n", id);
  }
  return 0;
}
