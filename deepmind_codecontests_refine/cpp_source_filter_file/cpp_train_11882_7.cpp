#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
bool isHappy(int k) {
  char s[64];
  int len = sprintf(s, "%d", k);
  for (int i = 0, _n = (len); i < _n; ++i)
    if (s[i] != '4' && s[i] != '7') return false;
  return true;
}
int n;
int d[100000];
int place[100000];
int d2[100000];
map<int, int> pos;
int good;
vector<pair<int, int> > sol;
void SWAP(int a, int b) {
  if (a == b) return;
  sol.push_back(pair<int, int>(a, b));
  swap(d[a], d[b]);
}
void solution() {
  scanf("%d", &n);
  good = -1;
  for (int i = 0, _n = (n); i < _n; ++i) {
    scanf("%d", d + i);
    if (isHappy(d[i])) good = i;
    d2[i] = d[i];
  }
  sort(d2, d2 + n);
  for (int i = 0, _n = (n); i < _n; ++i)
    if (!i || d2[i] != d2[i - 1]) pos[d2[i]] = i;
  if (good == -1) {
    for (int i = 0, _n = (n - 1); i < _n; ++i)
      if (d[i] > d[i + 1]) {
        puts("-1");
        return;
      }
    puts("0");
    return;
  }
  for (int it = 0, _n = (10); it < _n; ++it) {
    for (int i = 0; i < n; i++)
      if (d[i] != d2[i] && i != good) {
        int v = d[i];
        int& to = pos[v];
        while (d[to] == d2[to]) to++;
        SWAP(good, to);
        SWAP(i, to);
        good = i;
      }
  }
  printf("%d\n", (int)((sol).size()));
  for (int i = 0, _n = ((int)((sol).size())); i < _n; ++i)
    printf("%d %d\n", sol[i].first + 1, sol[i].second + 1);
  puts("");
}
int main() {
  solution();
  return 0;
}
