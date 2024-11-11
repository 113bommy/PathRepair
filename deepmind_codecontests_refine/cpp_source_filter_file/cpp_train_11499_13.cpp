#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const int maxn = 30;
int cnt[10];
set<pair<int, int> > ipt;
int all = 1 << 10, ans = INF;
int change(char x) {
  if (x == 'B')
    return 0;
  else if (x == 'Y')
    return 1;
  else if (x == 'W')
    return 2;
  else if (x == 'G')
    return 3;
  else
    return 4;
}
void fun(int num, set<pair<int, int> > st) {
  int one = 0, t[10] = {0};
  for (int j = 1, ct = 0; j < all; j <<= 1, ct++)
    if (num & j) {
      one++;
      t[ct] = 1;
    }
  for (int i = 0; i < (5); ++i)
    for (int j = (5); j < (10); ++j)
      if (t[i] && t[j]) st.erase(make_pair(i, j));
  for (int i = 0; i < (5); ++i)
    if (t[i]) {
      int num = 0, id;
      for (int j = (5); j < (10); ++j) {
        if (st.count(make_pair(i, j))) {
          num++;
          id = j;
        }
      }
      if (num == 1) st.erase(make_pair(i, id));
    }
  for (int j = (5); j < (10); ++j) {
    if (t[j]) {
      int num = 0, id;
      for (int i = 0; i < (5); ++i) {
        if (st.count(make_pair(i, j))) {
          num++;
          id = i;
        }
      }
      if (num == 1) st.erase(make_pair(id, j));
    }
  }
  if (st.size() <= 1) ans = min(ans, one);
}
int main() {
  int n;
  char x;
  int y;
  cin >> n;
  for (int i = 0; i < (n); ++i) {
    cin >> x >> y;
    ipt.insert(make_pair(change(x), y + 5));
  }
  for (int i = (0); i < (all); ++i) {
    fun(i, ipt);
  }
  printf("%d\n", ans);
  return 0;
}
