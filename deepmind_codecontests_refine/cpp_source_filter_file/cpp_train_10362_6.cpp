#include <bits/stdc++.h>
using namespace std;
int N, M, K, A, B, c, x;
set<pair<int, int> > s;
set<int> t;
bool f(int a, int b) {
  if (a > b) swap(a, b);
  return s.find(make_pair(a, b)) == s.end();
}
void dfs(int x) {
  vector<int> v;
  for (int i : t)
    if (f(x, i)) v.push_back(i);
  for (int i : v) t.erase(i);
  for (int i : v) dfs(i);
}
int main() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 2; i <= N; i++) t.insert(i);
  while (M--) {
    scanf("%d%d", &A, &B);
    if (A > B) swap(A, B);
    x += (A == 1);
    s.insert(make_pair(A, B));
  }
  for (int i = 2; i <= N; i++)
    if (f(1, i) && t.find(i) != t.end()) dfs(i), c++;
  printf((N - x <= K || c != K || t.size()) ? "impossible" : "possible");
}
