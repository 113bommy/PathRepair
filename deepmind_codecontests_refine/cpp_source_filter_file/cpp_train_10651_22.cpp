#include <bits/stdc++.h>
using namespace std;
const int M = 128;
struct G {
  char name[M];
  int id;
  int taxi, pizza, girl;
} g[M];
char tmp[M];
bool cmp1(const G &a, const G &b) {
  if (a.taxi == b.taxi) return a.id < b.id;
  return a.taxi > b.taxi;
}
bool cmp2(const G &a, const G &b) {
  if (a.pizza == b.pizza) return a.id < b.id;
  return a.pizza > b.pizza;
}
bool cmp3(const G &a, const G &b) {
  if (a.girl == b.girl) return a.id < b.id;
  return a.girl > b.girl;
}
int main() {
  int n, m;
  while (~scanf("%d", &n)) {
    g[n].taxi = g[n].pizza = g[n].girl = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d%s", &m, g[i].name);
      g[i].id = i;
      g[i].taxi = g[i].pizza = g[i].girl = 0;
      while (m--) {
        scanf("%s", tmp);
        int id = 0;
        for (int i = 0; tmp[i]; i++) {
          if (isdigit(tmp[i])) {
            tmp[id++] = tmp[i];
          }
        }
        tmp[id] = 0;
        bool flag = true;
        for (int i = 0; i < id - 1; i++) {
          if (tmp[i] != tmp[i + 1]) {
            flag = false;
            break;
          }
        }
        if (flag) {
          g[i].taxi++;
          continue;
        }
        flag = true;
        for (int i = 0; i < id - 1; i++) {
          if (tmp[i] <= tmp[i + 1]) {
            flag = false;
            break;
          }
        }
        if (flag) {
          g[i].pizza++;
        } else {
          g[i].girl++;
        }
      }
    }
    sort(g, g + n, cmp1);
    printf("If you want to call a taxi, you should call:");
    for (int i = 0; i < n; i++) {
      if (g[i].taxi == g[i + 1].taxi) {
        printf(" %s,", g[i].name);
      } else {
        printf(" %s.\n", g[i].name);
        break;
      }
    }
    sort(g, g + n, cmp2);
    printf("If you want to order a pizza, you should call:");
    for (int i = 0; i < n; i++) {
      if (g[i].pizza == g[i + 1].pizza) {
        printf(" %s,", g[i].name);
      } else {
        printf(" %s.\n", g[i].name);
        break;
      }
    }
    sort(g, g + n, cmp3);
    printf(
        "If you want to go to a cafe with a wonderful girl, you should call:");
    for (int i = 0; i < n; i++) {
      if (g[i].girl == g[i + 1].taxi) {
        printf(" %s,", g[i].name);
      } else {
        printf(" %s.\n", g[i].name);
        break;
      }
    }
  }
  return 0;
}
