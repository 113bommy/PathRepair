#include <bits/stdc++.h>
using namespace std;
vector<int> a, b;
vector<pair<int, int> > ans;
bool ask(vector<int> a, register int x) {
  printf("1\n1\n%d\n", a.size()), fflush(stdout);
  for (auto y : a) printf("%d ", y), fflush(stdout);
  printf("\n%d\n", x), fflush(stdout);
  return scanf("%d", &x), x;
}
int Get(vector<int>& a, register int x) {
  if (a.empty() || !ask(a, x)) return 0;
  vector<int>::iterator l = a.begin(), r = a.end() - 1, m;
  while (l < r)
    ask(vector<int>(a.begin(), (m = l + (r - l) / 2) + 1), x) ? r = m
                                                              : l = m + 1;
  a.erase(find(a.begin(), a.end() - 1, x = *l));
  return x;
}
void Solve(register int x, register int y = 0) {
  while ((y = Get(a, x))) Solve(y), b.push_back(y);
  while ((y = Get(b, x))) ans.push_back(pair<int, int>(x, y));
}
int main() {
  register int n;
  scanf("%d", &n);
  for (register int i = 2; i <= n; ++i) a.push_back(i);
  Solve(1);
  printf("ANSWER\n"), fflush(stdout);
  for (auto x : ans) printf("%d %d\n", x.first, x.second), fflush(stdout);
  return 0;
}
