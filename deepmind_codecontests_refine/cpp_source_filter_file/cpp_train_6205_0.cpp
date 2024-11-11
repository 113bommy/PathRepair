#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
vector<pair<int, int> > opt[18 * MAX];
map<pair<int, int>, vector<pair<int, int> > > mp;
int par[MAX];
int col[MAX];
int sz[MAX];
int an[MAX];
vector<int> roll_back_num;
vector<pair<pair<int, pair<int, int> >, pair<int, pair<int, int> > > >
    roll_back;
void insert(int t, int l, int r, int a, int b, int c, int d) {
  if (l > b || r < a) {
    return;
  }
  if (l >= a && r <= b) {
    opt[t].push_back(make_pair(c, d));
    return;
  }
  int mid = (l + r) / 2;
  insert(t * 2, l, mid, a, b, c, d);
  insert(t * 2 + 1, mid + 1, r, a, b, c, d);
}
int not_cor;
int find(int x) {
  while (x != par[x]) {
    x = par[x];
  }
  return x;
}
int color(int x) {
  int ans = 0;
  while (x != par[x]) {
    ans ^= col[x];
    x = par[x];
  }
  return (ans ^ col[x]);
}
void unite(int a, int b) {
  int ra = find(a), rb = find(b);
  int ca = color(a), cb = color(b);
  if (ra == rb) {
    if (ca == cb) {
      not_cor++;
      roll_back_num.push_back(-1);
    }
  } else {
    if (sz[ra] > sz[rb]) {
      swap(a, b);
      swap(ra, rb);
      swap(ca, cb);
    }
    roll_back.push_back({{ra, {ra, sz[ra]}}, {rb, {ca, sz[rb]}}});
    par[ra] = rb;
    sz[rb] += sz[ra];
    if (ca == cb) {
      col[ra] ^= 1;
    }
  }
}
void solve(int t, int l, int r) {
  int curn = roll_back_num.size();
  int cur = roll_back.size();
  for (auto it : opt[t]) {
    unite(it.first, it.second);
  }
  if (l == r) {
    if (not_cor) {
      an[l] = 0;
    } else {
      an[l] = 1;
    }
  } else {
    int mid = (l + r) / 2;
    solve(2 * t, l, mid);
    solve(2 * t + 1, mid + 1, r);
  }
  while (roll_back_num.size() > curn) {
    not_cor += roll_back_num.back();
    roll_back_num.pop_back();
  }
  while (roll_back.size() > cur) {
    pair<pair<int, pair<int, int> >, pair<int, pair<int, int> > > tmp =
        roll_back.back();
    par[tmp.first.first] = tmp.first.second.first;
    sz[tmp.first.first] = tmp.first.second.second;
    col[tmp.first.first] = tmp.second.second.first;
    sz[tmp.second.first] = tmp.second.second.second;
    roll_back.pop_back();
  }
}
int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= q; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a > b) {
      swap(a, b);
    }
    vector<pair<int, int> >& tmp = mp[make_pair(a, b)];
    if (tmp.empty() || (((tmp.back()).second) != -1)) {
      tmp.push_back(make_pair(i, -1));
    } else {
      (tmp.back()).second = (i - 1);
    }
  }
  for (auto it : mp) {
    for (auto it1 : it.second) {
      if (it1.second == -1) {
        it1.second = q;
      }
      insert(1, 1, q, it1.first, it1.second, it.first.first, it.first.second);
    }
  }
  for (int i = 1; i <= n; i++) {
    sz[i] = 1;
    par[i] = i;
  }
  solve(1, 1, q);
  for (int i = 1; i <= q; i++) {
    if (an[i] == 0) {
      printf("NO\n");
    } else {
      printf("YES\n");
    }
  }
  return 0;
}
