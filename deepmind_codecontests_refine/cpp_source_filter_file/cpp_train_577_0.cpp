#include <bits/stdc++.h>
using namespace std;
vector<int> PP[130];
vector<int> print(int x) {
  if ((int)PP[x].size() > 0) return PP[x];
  printf("? %d\n", x);
  fflush(stdout);
  int a;
  scanf("%d", &a);
  vector<int> v;
  for (int i = 0; i < a; i++) {
    int x;
    scanf("%d", &x);
    v.push_back(x);
  }
  return v;
}
void answer(int x) {
  printf("! %d\n", x);
  fflush(stdout);
}
int is_d(int pre, int x, int dep) {
  for (int i = 0; i < dep; i++) {
    PP[x] = print(x);
    if (i == dep - 1) break;
    int s = x;
    if (PP[x][0] == pre)
      x = PP[x][1];
    else
      x = PP[x][0];
    pre = s;
  }
  if ((int)PP[x].size() == 1)
    return 1;
  else
    return 0;
}
void Do(int p, int pp, int dep, int h) {
  if (dep == h) {
    answer(pp);
    return;
  }
  if ((int)PP[pp].size() == 0) PP[pp] = print(pp);
  if ((int)PP[pp].size() == 2) {
    answer(pp);
    return;
  }
  if (dep <= 4) {
    int t = PP[pp][0];
    if (t == p) t = PP[pp][1];
    if (!is_d(pp, t, dep - 1)) {
      Do(pp, t, dep + 1, h);
    } else {
      int a = -1;
      for (int i = 0; i < 3; i++)
        if (PP[pp][i] != t && PP[pp][i] != p) a = PP[pp][i];
      Do(pp, a, dep + 1, h);
    }
  } else {
    vector<int> v;
    v.push_back(pp);
    int a = -1, b = -1;
    for (int i = 0; i < 3; i++) {
      if (PP[pp][i] != p) {
        if (a == -1)
          a = PP[pp][i];
        else
          b = PP[pp][i];
      }
    }
    v.push_back(a);
    v.push_back(b);
    PP[a] = print(a);
    PP[b] = print(b);
    if ((int)PP[a].size() == 2) {
      answer(a);
      return;
    }
    if ((int)PP[b].size() == 2) {
      answer(b);
      return;
    }
    int c[4] = {-1, -1, -1, -1};
    for (int i = 0; i < 3; i++) {
      if (PP[a][i] != pp) {
        if (c[0] == -1)
          c[0] = PP[a][i];
        else
          c[1] = PP[a][i];
      }
    }
    for (int i = 0; i < 3; i++) {
      if (PP[b][i] != pp) {
        if (c[2] == -1)
          c[2] = PP[b][i];
        else
          c[3] = PP[b][i];
      }
    }
    for (int i = 0; i < 3; i++) {
      int e = c[i];
      PP[e] = print(e);
      if ((int)PP[e].size() == 2) {
        answer(e);
        return;
      }
    }
    answer(c[3]);
    return;
  }
}
void solve() {
  for (int i = 0; i < 130; i++) PP[i].clear();
  int h;
  scanf("%d", &h);
  if (h <= 4) {
    for (int i = 1; i < 1 << h; i++) {
      vector<int> v = print(i);
      if ((int)v.size() == 2) {
        answer(i);
        return;
      }
    }
  }
  int a = 127;
  vector<int> v;
  int pre = -1;
  while (1) {
    v.push_back(a);
    PP[a] = print(a);
    if ((int)PP[a].size() == 1) break;
    if ((int)PP[a].size() == 2) {
      answer(a);
      return;
    }
    int t = pre;
    pre = a;
    if (t == PP[a][0])
      a = PP[a][1];
    else
      a = PP[a][0];
  }
  int L = (int)v.size();
  int mL = (L + 3) / 2;
  if (L == 1) {
    Do(a, PP[a][0], 2, h);
  } else {
    int p = v[(int)v.size() - mL + 1];
    int pp = v[(int)v.size() - mL];
    Do(p, pp, mL, h);
  }
}
int main() {
  int Tc = 1;
  scanf("%d", &Tc);
  for (int tc = 1; tc <= Tc; tc++) {
    solve();
  }
  return 0;
}
