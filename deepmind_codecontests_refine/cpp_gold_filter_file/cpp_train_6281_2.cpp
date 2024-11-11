#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
int tin[100009], n, TIM, P[100009][19], lvl[100009];
long long C[100009][19];
vector<pair<int, int> > adj[100009];
void dfs(int nd, int pr, int last) {
  tin[nd] = ++TIM;
  P[nd][0] = pr;
  C[nd][0] = last;
  lvl[nd] = (~pr ? lvl[pr] + 1 : 1);
  for (typeof((adj[nd]).begin()) it = (adj[nd]).begin(); it != (adj[nd]).end();
       it++)
    if (it->first != pr) dfs(it->first, nd, it->second);
}
set<pair<int, int> > s;
void build() {
  for (int j = 1; j <= 17; j++)
    for (int i = 1; i <= n; i++)
      if (~P[i][j - 1]) {
        P[i][j] = P[P[i][j - 1]][j - 1];
        C[i][j] = C[i][j - 1] + C[P[i][j - 1]][j - 1];
      }
}
long long dis(int x, int y) {
  long long res = 0;
  if (lvl[x] < lvl[y]) swap(x, y);
  for (int i = 17; i >= 0; i--)
    if (lvl[x] - (1 << i) >= lvl[y]) {
      res += C[x][i];
      x = P[x][i];
    }
  if (x == y) return res;
  for (int i = 17; i >= 0; i--)
    if (~P[x][i] and P[x][i] != P[y][i]) {
      res += C[x][i];
      x = P[x][i];
      res += C[y][i];
      y = P[y][i];
    }
  res += C[x][0];
  res += C[y][0];
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }
  dfs(1, -1, 0);
  build();
  int q;
  scanf("%d", &q);
  long long ans = 0;
  while (q--) {
    char c;
    scanf(" %c", &c);
    if (c == '?')
      printf("%lld\n", ans / 2);
    else if (c == '+') {
      int x;
      scanf("%d", &x);
      if (s.size() != 0) {
        pair<int, int> st = *s.begin();
        pair<int, int> en = *s.rbegin();
        if (st.first > tin[x]) {
          ans -= dis(st.second, en.second);
          ans += dis(x, st.second);
          ans += dis(x, en.second);
        } else if (en.first < tin[x]) {
          ans -= dis(st.second, en.second);
          ans += dis(en.second, x);
          ans += dis(st.second, x);
        } else {
          pair<int, int> cep = *(--s.lower_bound(make_pair(tin[x], -1)));
          pair<int, int> sag = *s.lower_bound(make_pair(tin[x], -1));
          ans -= dis(cep.second, sag.second);
          ans += dis(cep.second, x);
          ans += dis(x, sag.second);
        }
      }
      s.insert(make_pair(tin[x], x));
    } else {
      int x;
      scanf("%d", &x);
      if (s.size() > 1) {
        pair<int, int> st = *s.begin();
        pair<int, int> en = *s.rbegin();
        if (st.first == tin[x]) {
          st = *s.upper_bound(make_pair(tin[x], 1000000007));
          ans -= dis(x, st.second);
          ans -= dis(x, en.second);
          ans += dis(st.second, en.second);
        } else if (en.first == tin[x]) {
          en = *(--s.lower_bound(make_pair(tin[x], -1)));
          ans -= dis(en.second, x);
          ans -= dis(st.second, x);
          ans += dis(st.second, en.second);
        } else {
          typeof((s).begin()) it = s.lower_bound(make_pair(tin[x], -1));
          it--;
          pair<int, int> cep = *it;
          it++;
          it++;
          pair<int, int> sag = *it;
          ans -= dis(cep.second, x);
          ans -= dis(x, sag.second);
          ans += dis(cep.second, sag.second);
        }
      } else
        ans = 0;
      s.erase(make_pair(tin[x], x));
    }
  }
  return 0;
}
