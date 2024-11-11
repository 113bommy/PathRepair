#include <bits/stdc++.h>
using namespace std;
int n;
int d[30];
vector<pair<int, int> > res;
int ot(int a, int b) {
  for (int i = 1; i <= 3; i++)
    if (i != a && i != b) return i;
  return 0;
}
void solve2(int ini, int fim, int p1, int p2) {
  if (ini > fim) {
    return;
  }
  int x = ini;
  while (x <= fim && d[x] == d[ini]) x++;
  x--;
  solve2(x + 1, fim, p1, ot(p1, p2));
  for (int i = ini; i <= x; i++) res.push_back(make_pair(p1, p2));
  solve2(x + 1, fim, ot(p1, p2), p2);
}
void solve(int ini, int fim, int p1, int p2) {
  if (ini > fim) {
    return;
  }
  int x = ini;
  while (x <= fim && d[x] == d[ini]) x++;
  x--;
  if (x > ini && x < fim) {
    solve2(x + 1, fim, p1, p2);
    for (int i = ini; i <= x; i++) res.push_back(make_pair(p1, ot(p1, p2)));
    solve2(x + 1, fim, p2, p1);
    for (int i = ini; i <= x; i++) res.push_back(make_pair(ot(p1, p2), p1));
    solve(x + 1, fim, p1, p2);
  } else if (x > ini) {
    for (int i = ini; i < x; i++) res.push_back(make_pair(p1, ot(p1, p2)));
    res.push_back(make_pair(p1, p2));
    for (int i = ini; i < x; i++) res.push_back(make_pair(ot(p1, p2), p1));
  } else {
    solve2(ini + 1, fim, p1, ot(p1, p2));
    res.push_back(make_pair(p1, p2));
    solve2(ini + 1, fim, ot(p1, p2), p2);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &d[i]);
  }
  solve(0, n - 1, 1, 3);
  printf("%d\n", res.size());
  for (int i = 0; i < res.size(); i++)
    printf("%d %d\n", res[i].first, res[i].second);
  return 0;
}
