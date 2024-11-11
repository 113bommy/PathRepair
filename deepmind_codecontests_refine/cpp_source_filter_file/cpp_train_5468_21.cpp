#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200100;
multiset<int> s;
deque<pair<int, int> > q;
int n, m, p[MAXN], a, b, maksi, sol[MAXN], tag[MAXN];
void ubaci(pair<int, int> x) {
  while (!q.empty() && q.back().first <= x.first) q.pop_back();
  q.push_back(x);
}
void solve() {
  pair<int, int> x;
  int tmp = -1;
  for (int i = n - 1; i >= 0; i--) {
    if (!q.empty() && q.front().first == i)
      tmp = q.front().second, q.pop_front();
    tag[i] = tmp;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (tag[i] == -1) {
      sol[i] = p[i];
      s.erase(s.find(p[i]));
    }
    if (tag[i] == 2) {
      sol[i] = *s.begin();
      s.erase(s.begin());
    }
    if (tag[i] == 1) {
      sol[i] = *s.rbegin();
      s.erase(--s.end());
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = (0); i < int(n); i++) scanf("%d", &p[i]), s.insert(p[i]);
  for (int i = (0); i < int(n); i++) {
    scanf("%d %d", &a, &b);
    b--;
    ubaci(make_pair(b, a));
  }
  solve();
  for (int i = (0); i < int(n); i++) printf("%d ", sol[i]);
  puts("");
  return 0;
}
