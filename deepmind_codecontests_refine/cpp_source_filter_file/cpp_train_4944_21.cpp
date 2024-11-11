#include <bits/stdc++.h>
using namespace std;
vector<int> tab[100005];
int n, t;
int k1, k2;
queue<int> s1, s2;
void pl(queue<int> s) {
  while (!s.empty()) tab[t].push_back(s.front()), s.pop();
}
bool ch(queue<int> s, int p) {
  if (tab[p].size() != s.size()) return 0;
  for (int i = 0; i < tab[p].size(); i++) {
    int u = tab[p][i];
    int v = s.front();
    s.pop();
    if (u != v) return 0;
  }
  return 1;
}
int main() {
  scanf("%d", &n);
  t = 0;
  int v;
  scanf("%d", &k1);
  for (int i = 0; i < k1; i++) scanf("%d", &v), s1.push(v);
  scanf("%d", &k2);
  for (int i = 0; i < k2; i++) scanf("%d", &v), s2.push(v);
  while (1) {
    pl(s1);
    int u = s1.front();
    int v = s2.front();
    s1.pop();
    s2.pop();
    t++;
    if (u > v) {
      s1.push(v);
      s1.push(u);
    } else {
      s2.push(u);
      s2.push(v);
    }
    if (s1.empty()) {
      printf("%d %d", t, 2);
      return 0;
    }
    if (s2.empty()) {
      printf("%d %d", t, 1);
      return 0;
    }
    for (int i = 0; i < t - 50; i++)
      if (ch(s1, i)) {
        printf("-1");
        return 0;
      }
  }
}
