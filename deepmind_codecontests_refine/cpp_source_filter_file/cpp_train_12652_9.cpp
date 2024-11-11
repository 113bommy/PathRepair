#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 7;
const int MAXN = (int)3e6 + 7;
int a, ta;
int b, tb;
int h, m;
int st;
int main() {
  scanf("%d%d%d%d", &a, &ta, &b, &tb);
  scanf("%d:%d", &h, &m);
  vector<pair<int, int> > seg;
  for (int i = 300; i < 24 * 60; i += b) {
    seg.push_back(make_pair(i, i + tb));
  }
  int l = h * 60 + m + 1;
  int r = l + ta - 2;
  int ans = 0;
  for (auto it : seg) {
    if (max(it.first, l) <= min(it.second, r)) {
      ans++;
    }
  }
  cout << ans;
  return 0;
}
