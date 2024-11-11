#include <bits/stdc++.h>
using namespace std;
void Rd(int &res) {
  res = 0;
  char c;
  while (c = getchar(), c < 48)
    ;
  do res = res * 10 + (c & 15);
  while (c = getchar(), c > 47);
}
vector<int> num[5005], ans, id;
int n, k, a, x, y, m, tot, L[5005];
struct node {
  int id, v;
  bool operator<(const node &tmp) const { return v < tmp.v; }
};
multiset<node> st;
void solve_small() {
  for (int i = 1; i <= n; i++) st.insert((node){i, num[i][0]});
  ans.push_back(-1);
  id.push_back(-1);
  int allc = 0;
  while (tot--) {
    multiset<node>::iterator it =
        st.lower_bound((node){1, ans[ans.size() - 1]});
    if (it != st.end()) {
      node tmp = *it;
      id.push_back(tmp.id);
      ans.push_back(tmp.v);
      st.erase(it);
      if (L[tmp.id] + 1 < num[tmp.id].size())
        st.insert((node){tmp.id, num[tmp.id][++L[tmp.id]]});
      continue;
    }
    allc++;
    it = st.begin();
    node tmp = *it;
    id.push_back(tmp.id);
    ans.push_back(tmp.v);
    st.erase(it);
    if (L[tmp.id] + 1 < num[tmp.id].size())
      st.insert((node){tmp.id, num[tmp.id][++L[tmp.id]]});
  }
  printf("%d\n", allc);
  for (int i = 1; i < ans.size(); i++) printf("%d %d\n", ans[i], id[i]);
}
void solve_big() {
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    int res = 0;
    for (int j = 1; j < num[i].size(); j++)
      if (num[i][j] < num[i][j - 1]) res++;
    mx = max(res, mx);
  }
  printf("%d\n", mx);
}
int main() {
  Rd(n);
  for (int i = 1; i <= n; i++) {
    Rd(k), Rd(a), Rd(x), Rd(y), Rd(m);
    tot += k;
    num[i].push_back(a);
    for (int j = 2; j <= k; j++) {
      a = (1LL * a * x + y) % m;
      num[i].push_back(a);
    }
  }
  if (tot <= 200000)
    solve_small();
  else
    solve_big();
  return 0;
}
