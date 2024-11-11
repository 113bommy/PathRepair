#include <bits/stdc++.h>
using namespace std;
int n, a, b, bylo[100007], uzyte[100007], t[100007];
vector<int> v[100007];
bool mozna;
bool check(int x) {
  bylo[t[(x - 1 + n) % n]] = 1;
  bylo[t[(x - 2 + n) % n]] = 1;
  bylo[t[(x + 1) % n]] = 1;
  bylo[t[(x + 2) % n]] = 1;
  for (__typeof((v[t[x]]).begin()) it = ((v[t[x]]).begin());
       it != (v[t[x]]).end(); it++)
    --bylo[*it];
  for (__typeof((v[t[x]]).begin()) it = ((v[t[x]]).begin());
       it != (v[t[x]]).end(); it++)
    if (bylo[*it] != 0) return false;
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < (2 * n); i++) {
    scanf("%d%d", &a, &b);
    v[a].push_back(b);
    v[b].push_back(a);
  }
  mozna = true;
  for (int i = 1; i <= (n); i++)
    if (int(v[i].size()) != 4) mozna = false;
  if (!mozna) {
    puts("-1");
    return 0;
  }
  for (int k = 0; k < (24); k++) {
    t[0] = v[1][0];
    t[1] = v[1][1];
    t[2] = 1;
    t[3] = v[1][2];
    t[4] = v[1][3];
    for (int i = 0; i < (5); i++) uzyte[t[i]] = 1;
    mozna = true;
    for (int i = 3; i <= (n - 3); i++) {
      bylo[t[i - 1]] = 1;
      bylo[t[i - 2]] = 1;
      bylo[t[i + 1]] = 1;
      for (__typeof((v[t[i]]).begin()) it = ((v[t[i]]).begin());
           it != (v[t[i]]).end(); it++)
        --bylo[*it];
      if (bylo[t[i - 1]] == 0 && bylo[t[i - 2]] == 0 && bylo[t[i + 1]] == 0) {
        for (__typeof((v[t[i]]).begin()) it = ((v[t[i]]).begin());
             it != (v[t[i]]).end(); it++)
          if (bylo[*it] == -1 && !uzyte[*it]) {
            bylo[*it] = 0;
            uzyte[*it] = 1;
            t[i + 2] = *it;
          }
        if (t[i + 2] == 0) mozna = false;
      } else
        mozna = false;
      if (mozna == false) break;
    }
    if (mozna) {
      for (int i = 0; i < (n); i++)
        if (!check(i)) mozna = false;
      if (mozna) {
        for (int i = 0; i < (n); i++) printf("%d ", t[i]);
        puts("");
        return 0;
      }
    }
    for (int i = 0; i < (n); i++) t[i] = bylo[i] = uzyte[i] = 0;
    next_permutation(v[1].begin(), v[1].end());
  }
  puts("-1");
  return 0;
}
