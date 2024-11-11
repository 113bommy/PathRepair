#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
char ds[2][N][10];
int sz[2];
vector<int> tudo[2], nham[2], trong[2];
bool chiem[N];
char s[100];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    int t;
    scanf("%d", &t);
    strcpy(ds[t][sz[t]++], s);
  }
  int m = sz[1];
  int kq = n;
  for (int t = 0; t < 2; t++)
    for (int i = 0; i < sz[t]; i++) {
      int so = -1;
      if (ds[t][i][0] > '0') {
        so = 0;
        for (int j = 0; ds[t][i][j]; j++) {
          int c = ds[t][i][j];
          if (c < '0' || c > '9') {
            so = -1;
            break;
          }
          so = so * 10 + (c - '0');
        }
      }
      if (so <= 0 || so > n) {
        tudo[t].push_back(i);
        continue;
      }
      chiem[so] = true;
      if ((t == 1 && so > m) || (t == 0 && so <= m)) {
        nham[t ^ 1].push_back(so);
        continue;
      }
      kq--;
    }
  for (int i = 1; i <= m; i++)
    if (!chiem[i]) trong[1].push_back(i);
  for (int i = m + 1; i <= n; i++)
    if (!chiem[i]) trong[0].push_back(i);
  int luu = -1;
  if (trong[0].empty() && trong[1].empty()) {
    if (nham[0].empty() && nham[1].empty()) {
      printf("0");
      return 0;
    }
    printf("%d\n", kq + 1);
    printf("move %d %d\n", nham[0].back(), n + 1);
    luu = 0;
    trong[0].push_back(nham[0].back());
    nham[0].pop_back();
  } else {
    printf("%d\n", kq);
  }
  while (!nham[0].empty() && !nham[1].empty()) {
    if (!trong[0].empty()) {
      printf("move %d %d\n", nham[1].back(), trong[0].back());
      trong[0].pop_back();
      trong[1].push_back(nham[1].back());
      nham[1].pop_back();
    } else {
      printf("move %d %d\n", nham[0].back(), trong[1].back());
      trong[1].pop_back();
      trong[0].push_back(nham[0].back());
      nham[0].pop_back();
    }
  }
  for (auto &u : nham[0]) {
    printf("move %d %d\n", u, trong[1].back());
    trong[1].pop_back();
    trong[0].push_back(u);
  }
  for (auto &u : nham[1]) {
    printf("move %d %d\n", u, trong[0].back());
    trong[0].pop_back();
    trong[1].push_back(u);
  }
  for (auto &u : tudo[0]) {
    printf("move %s %d\n", ds[0][u], trong[0].back());
    trong[0].pop_back();
  }
  for (auto &u : tudo[1]) {
    printf("move %s %d\n", ds[1][u], trong[1].back());
    trong[1].pop_back();
  }
  if (luu == 0)
    printf("move %d %d\n", n + 1, trong[1].back());
  else if (luu == 1)
    printf("move %d %d\n", n + 1, trong[0].back());
}
