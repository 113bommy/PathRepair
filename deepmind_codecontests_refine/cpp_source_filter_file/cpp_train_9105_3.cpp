#include <bits/stdc++.h>
using namespace std;
int n;
map<pair<int, int>, int> mp;
pair<int, int> point[100005];
int status[100005];
int tree[1 << 18];
vector<int> v;
void push(int in, int cs, int s, int e, int val) {
  if (s == e) {
    tree[cs] = val;
    return;
  }
  int md = (s + e) / 2;
  if (in <= md)
    push(in, 2 * cs, s, md, val);
  else
    push(in, 2 * cs + 1, md + 1, e, val);
  tree[cs] = tree[2 * cs] + tree[2 * cs + 1];
  return;
}
bool exist(int x, int y) {
  int cn = mp[make_pair(x, y)];
  if (cn == 0 || status[cn] == 2) return false;
  return true;
}
bool dependent(int x, int y) {
  if (!exist(x, y)) return false;
  int cnt = 0;
  if (exist(x - 1, y - 1)) cnt++;
  if (exist(x, y - 1)) cnt++;
  if (exist(x + 1, y - 1)) cnt++;
  if (cnt == 1) return true;
  return false;
}
bool can_move(int x, int y) {
  if (!exist(x, y)) return false;
  int cn = mp[make_pair(x, y)];
  if (dependent(x - 1, y + 1)) return false;
  if (dependent(x, y + 1)) return false;
  if (dependent(x + 1, y + 1)) return false;
  return true;
}
void make_status_0(int x, int y) {
  int cn = mp[make_pair(x, y)];
  status[cn] = 0;
  push(cn, 1, 1, n, 0);
}
void keep_base(int x, int y) {
  if (exist(x - 1, y - 1)) {
    make_status_0(x - 1, y - 1);
  } else if (exist(x, y - 1)) {
    make_status_0(x, y - 1);
  } else if (exist(x + 1, y - 1)) {
    make_status_0(x + 1, y - 1);
  }
}
void insert_tree(int x, int y) {
  int cn = mp[make_pair(x, y)];
  push(cn, 1, 1, n, 1);
  status[cn] = 1;
}
void do_effect(int in) {
  int x = point[in].first;
  int y = point[in].second;
  if (dependent(x - 1, y + 1)) keep_base(x - 1, y + 1);
  if (dependent(x, y + 1)) keep_base(x, y + 1);
  if (dependent(x + 1, y + 1)) keep_base(x + 1, y + 1);
  if (can_move(x - 1, y - 1)) {
    insert_tree(x - 1, y - 1);
  }
  if (can_move(x, y - 1)) {
    insert_tree(x, y - 1);
  }
  if (can_move(x + 1, y - 1)) {
    insert_tree(x + 1, y - 1);
  }
}
int get_max_in(int cs, int s, int e) {
  if (s == e) {
    return s;
  }
  int md = (s + e) / 2;
  if (tree[2 * cs + 1]) return get_max_in(2 * cs + 1, md + 1, e);
  if (tree[2 * cs]) return get_max_in(2 * cs, s, md);
  return 0;
}
int get_min_in(int cs, int s, int e) {
  if (s == e) {
    return s;
  }
  int md = (s + e) / 2;
  if (tree[2 * cs]) return get_min_in(2 * cs, s, md);
  if (tree[2 * cs + 1]) return get_min_in(2 * cs + 1, md + 1, e);
  return 0;
}
void build_no() {
  long long no = 0;
  long long pw = 1;
  for (int i = v.size() - 1; i >= 0; i--) {
    no += pw * v[i];
    no %= (100000000 + 9);
    pw *= n;
    pw %= (100000000 + 9);
  }
  cout << no << endl;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    point[i] = make_pair(x, y);
    mp[point[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    int x = point[i].first;
    int y = point[i].second;
    if (can_move(x, y)) {
      insert_tree(x, y);
    }
  }
  int ci = 0;
  while (1) {
    int cn = ci ? get_min_in(1, 1, n) : get_max_in(1, 1, n);
    ci = (ci + 1) % 2;
    if (cn == 0) break;
    status[cn] = 2;
    push(cn, 1, 1, n, 0);
    v.push_back(cn - 1);
    do_effect(cn);
  }
  build_no();
  return 0;
}
