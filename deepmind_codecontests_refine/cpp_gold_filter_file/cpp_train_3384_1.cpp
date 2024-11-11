#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double PI = acos(-1);
const int INF = (int)1e9 + 7;
const int MAXN = (int)1e6 + 7;
int n;
int a[MAXN];
bool fix[MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  vector<pair<int, int> > all;
  int ptr = 1;
  while (ptr <= n) {
    int nxt = ptr;
    while (nxt <= n && a[nxt] == a[ptr]) nxt++;
    all.push_back(make_pair(a[ptr], nxt - ptr));
    ptr = nxt;
  }
  fix[0] = 1;
  fix[all.size() - 1] = 1;
  for (int i = 1; i < all.size(); i++)
    if (all[i].second > 1) fix[i] = 1;
  int moves = 0;
  ptr = 0;
  vector<int> ans;
  while (ptr < all.size()) {
    if (fix[ptr]) {
      for (int i = 0; i < all[ptr].second; i++) ans.push_back(all[ptr].first);
      ptr++;
    } else {
      int blocks = 0;
      int st = all[ptr - 1].first;
      while (ptr < all.size() && !fix[ptr]) {
        blocks++;
        ptr++;
      }
      int en = all[ptr].first;
      moves = max(moves, (blocks + 1) / 2);
      for (int i = 0; i < blocks / 2; i++) ans.push_back(st);
      for (int i = 0; i < (blocks + 1) / 2; i++) ans.push_back(en);
    }
  }
  printf("%d\n", moves);
  for (auto it : ans) printf("%d ", it);
  return 0;
}
