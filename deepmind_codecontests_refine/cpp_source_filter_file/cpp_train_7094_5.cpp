#include <bits/stdc++.h>
using namespace std;
int x[100010], y[100010], c, np[100010], ok[100010], ls[100010], t[100010],
    p[100010], l[100010];
char s[100010];
vector<int> r[100010];
void ask(int t) {
  if (!c) return;
  printf("Q %d ", c);
  if (!t) {
    for (int i = 1; i <= c; i++) printf("%d %d ", x[i], y[i]);
  } else {
    for (int i = 1; i <= c; i++) printf("%d %d ", np[x[i]], np[y[i]]);
  }
  puts("");
  fflush(stdout);
  scanf("%s", s + 1);
  if (!t) {
    for (int i = 1; i <= c; i++) ok[x[i]] = s[i] - '1';
  } else {
    for (int i = 1; i <= c; i++) ls[y[i]] = s[i] - '1';
  }
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    c = 0;
    for (int i = 1; i < n; i += 2) {
      x[++c] = i;
      y[c] = i + 1;
    }
    ask(0);
    c = 0;
    for (int i = 2; i < n; i += 2) {
      x[++c] = i;
      y[c] = i + 1;
    }
    ask(0);
    int d = 0;
    for (int i = 1; i <= n; i++)
      if (!ok[i - 1]) np[++d] = i;
    for (int j = 1; j < 4; j += 2) {
      c = 0;
      for (int i = j; i + 2 <= d; i += 4) {
        x[++c] = i;
        y[c] = i + 2;
      }
      for (int i = j + 1; i + 2 <= d; i += 4) {
        x[++c] = i;
        y[c] = i + 2;
      }
      ask(1);
    }
    r[0].clear();
    r[1].clear();
    r[2].clear();
    t[1] = p[np[1]] = 0;
    t[2] = p[np[2]] = 1;
    for (int i = 3; i <= d; i++) {
      if (ls[i])
        t[i] = p[np[i]] = t[i - 2];
      else
        t[i] = p[np[i]] = 3 - t[i - 1] - t[i - 2];
    }
    for (int i = 1; i <= n; i++) {
      if (ok[i - 1])
        l[i] = l[i - 1];
      else
        l[i] = i;
    }
    for (int i = 1; i <= n; i++) r[p[l[i]]].push_back(i);
    printf("A %d %d %d\n", r[0].size(), r[1].size(), r[2].size());
    for (int i = 0; i < 3; i++) {
      for (int j : r[i]) printf("%d ", j);
      puts("");
    }
    fflush(stdout);
  }
}
