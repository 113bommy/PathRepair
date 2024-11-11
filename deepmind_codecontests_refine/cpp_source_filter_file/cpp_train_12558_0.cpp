#include <bits/stdc++.h>
using namespace std;
set<int> st[500];
int tree[100010];
void update(int i, int limit, int val) {
  while (i <= limit) {
    tree[i] += val;
    i += (i) & (-i);
  }
}
int query(int i) {
  int sum = 0;
  while (i > 0) {
    sum += tree[i];
    i -= (i) & (-i);
  }
  return sum;
}
int go(int x) {
  int b = 1;
  int e = 100010 - 1;
  while (b <= e) {
    int mid = (b + e) / 2;
    int val = query(mid);
    if (val >= x)
      e = mid - 1;
    else
      b = mid + 1;
  }
  return b;
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  string s;
  cin >> s;
  s = ' ' + s;
  for (int i = 1; i <= n; i++) {
    st[s[i]].insert(i);
  }
  for (int i = 1; i <= n; i++) {
    update(i, 100010 - 1, 1);
  }
  while (m--) {
    char c[2];
    int x, y;
    scanf("%d %d", &x, &y);
    scanf("%s", c);
    int l = go(x);
    int r = go(y);
    char t = c[0];
    auto it1 = st[t].lower_bound(l);
    auto it2 = st[t].upper_bound(r);
    vector<int> v;
    while (true) {
      if (it1 == it2) break;
      v.push_back(*it1);
      it1++;
    }
    for (int i = 0; i < v.size(); i++) {
      update(v[i], 100010 - 1, -1);
      st[t].erase(v[i]);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (st[s[i]].find(i) != st[s[i]].end()) {
      printf("%c", s[i]);
    }
  }
  printf("\n");
  return 0;
}
