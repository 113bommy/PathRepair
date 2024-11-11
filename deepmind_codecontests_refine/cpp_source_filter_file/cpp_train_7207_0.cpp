#include <bits/stdc++.h>
using namespace std;
int diffLookup[301];
int inc[301], a[301];
int n;
int ot, oc;
pair<int, int> ask(int u) {
  printf("? %d\n", u);
  fflush(stdout);
  int a, b;
  scanf("%d%d", &a, &b);
  return make_pair(a, b);
}
int get(int v1, int v2) {
  if (v1 < 1 || v2 < 1) return 0;
  int p1 = (v1 == 1 ? a[1] + 2 : a[v1] + 1);
  int p2 = (v2 == 1 ? a[1] + 2 : a[v2] + 1);
  return p1 * p2;
}
void deal(int u) {
  if (u == n) {
    for (int i = 1; i <= n - 3; i++) {
      int id1 = (i == 1 ? a[i] + 2 : a[i] + 1);
      int id2 = a[i + 1] + 1;
      int id3 = a[i + 2] + 1;
      oc -= (id1 * id2 * id3);
    }
    int v1 = a[n - 1] + 1;
    int v2 = a[n - 2] + 1;
    a[n] = oc / (v1 * v2);
    printf("!");
    for (int i = 1; i <= n; i++) printf(" %d", a[i]);
    puts("");
    return;
  }
  if (u == 1) {
    pair<int, int> a1 = ask(1);
    inc[1] = a1.second - oc;
    pair<int, int> a2 = ask(2);
    inc[2] = a2.second - a1.second;
    if (inc[2] == 0) {
      a[3] = 0;
    }
    pair<int, int> a3 = ask(3);
    inc[3] = a3.second - a2.second;
    if (a[3] == -1) {
      int diff = a3.first - a2.first;
      int good;
      for (int j = 1; j <= n + 5; j++)
        if (diffLookup[j] == diff) good = j;
      a[3] = good - 1;
    }
    pair<int, int> a11 = ask(1);
    int diff = a11.first - a3.first;
    int good;
    for (int j = 1; j <= n + 5; j++)
      if (diffLookup[j] == diff) good = j;
    a[1] = good - 2;
    a[2] = (a11.second - a3.second) / (a[3] + 1) - 1;
    ot = a11.first;
    oc = a11.second;
    if (inc[3] - (a[1] + 1) * (a[2] + 1) == 0) {
      a[4] = 0;
    }
    deal(4);
  } else {
    pair<int, int> hihi = ask(u);
    if (a[u] == -1) {
      int diff = hihi.first - ot;
      int good;
      for (int j = 1; j <= n + 5; j++)
        if (diffLookup[j] == diff) good = j;
      a[1] = good - 2;
    }
    if (hihi.second - oc == (a[u - 1] + 1) * (a[u - 2] + 1)) {
      a[u + 1] = 0;
    }
    ot = hihi.first;
    oc = hihi.second;
    deal(u + 1);
  }
}
int main() {
  scanf("%d", &n);
  scanf("%d%d", &ot, &oc);
  int last = 0;
  for (int i = 1; i <= n + 5; i++) {
    int nw = i * (i - 1) * (i - 2);
    diffLookup[i] = nw - last;
    last = nw;
  }
  for (int i = 1; i <= n; i++) a[i] = -1;
  deal(1);
}
