#include <bits/stdc++.h>
using namespace std;
int n, siz[200005], l[200005], r[200005], a[200005], p[200005], an = 0,
                                                                b[200005];
bool vis[200005];
vector<int> vt[200005], vec;
set<int> st;
set<int>::iterator it;
int root(int node) {
  while (p[node] != node) {
    p[node] = p[p[node]];
    node = p[node];
  }
  return node;
}
int merging(int n1, int n2) {
  int p1 = root(n1), p2 = root(n2);
  if (p1 == 0) return p2;
  if (p2 == 200005 - 1) return p1;
  if (p1 == p2) return p1;
  if (siz[p1] > siz[p2]) {
    siz[p1] += siz[p2];
    p[p2] = p[p1];
    l[p1] = min(l[p1], l[p2]);
    r[p1] = max(r[p1], r[p2]);
    return p1;
  } else {
    siz[p2] += siz[p1];
    p[p1] = p[p2];
    l[p2] = min(l[p2], l[p1]);
    r[p2] = max(r[p1], r[p2]);
    return p2;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  scanf("%d", &n);
  int lef = 1, cur = 1, ri;
  st.insert(0);
  st.insert(200005 - 1);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (i != 1 && a[i] != a[i - 1]) {
      l[cur] = lef, r[cur] = i - 1;
      siz[cur] = r[cur] - l[cur] + 1;
      vt[siz[cur]].push_back(l[cur]);
      p[cur] = cur;
      cur++;
      lef = i;
    }
    st.insert(i);
    b[i] = cur;
  }
  l[cur] = lef, r[cur] = n, siz[cur] = n - lef + 1;
  vt[siz[cur]].push_back(l[cur]);
  p[cur] = cur;
  for (int i = 200005 - 1; i >= 1; i--) {
    sort(vt[i].begin(), vt[i].end());
    for (int j = 0, par, tmp, tpp, lol, now; j < vt[i].size(); j++) {
      now = vt[i][j];
      if (vis[now]) continue;
      par = root(b[now]);
      it = st.lower_bound(l[par]);
      it--;
      tmp = *it;
      it = st.lower_bound(r[par]);
      it++;
      tpp = *it;
      if (a[tmp] == a[tpp] && a[tmp]) {
        lol = merging(b[tmp], b[tpp]);
        if (siz[lol] >= i) {
          vt[i][j] = lol;
          j--;
        } else
          vt[siz[lol]].push_back(l[lol]);
      }
      for (it = st.lower_bound(l[par]); *it <= r[par]; it++) vec.push_back(*it);
      for (int k = 0; k < vec.size(); k++) {
        st.erase(vec[k]), vis[vec[k]] = true;
      }
      vec.clear();
      an++;
    }
  }
  printf("%d\n", an);
  return 0;
}
