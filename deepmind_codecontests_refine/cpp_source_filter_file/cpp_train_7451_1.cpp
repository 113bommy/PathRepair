#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
char s[22], t[22];
string a[N];
map<string, int> idx;
int p[N], op[N];
void init() {
  for (int i = 0; i < N; ++i) {
    p[i] = i;
    if (i + N / 2 < N) {
      op[i] = i + N / 2;
    }
  }
}
int root(int i) { return p[i] = i == p[i] ? i : root(p[i]); }
int opposite(int i) { return root(op[root(i)]); }
void merge(int x, int y) { p[root(x)] = root(y); }
bool check(int i, int j) { return root(i) == root(j); }
int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    a[i] = s;
    idx[a[i]] = i + 1;
  }
  init();
  while (m--) {
    int r;
    scanf("%d %s %s", &r, s, t);
    int x = idx[string(s)];
    int y = idx[string(t)];
    if (r == 1) {
      if (check(x, opposite(y))) {
        puts("NO");
      } else {
        puts("YES");
        merge(x, y);
        merge(opposite(x), opposite(y));
      }
    } else {
      if (check(x, y)) {
        puts("NO");
      } else {
        puts("YES");
        merge(opposite(x), y);
        merge(opposite(y), x);
      }
    }
  }
  while (q--) {
    scanf("%s %s", s, t);
    int x = idx[string(s)];
    int y = idx[string(t)];
    if (check(x, y)) {
      puts("1");
    } else if (check(x, opposite(y))) {
      puts("2");
    } else {
      puts("3");
    }
  }
}
