#include <bits/stdc++.h>
using namespace std;
struct Node {
  int l, r;
  int s;
  Node() {
    l = r = -1;
    s = 0;
  }
};
vector<Node> t;
int n, m;
void inc(int v, int l, int r, int p, int c) {
  t[v].s += c;
  if (l == r) return;
  if (t[v].l == -1) {
    t[v].l = t.size();
    t.push_back(Node());
  }
  if (t[v].r == -1) {
    t[v].r = t.size();
    t.push_back(Node());
  }
  int mid = (l + r) / 2;
  if (p <= mid) {
    inc(t[v].l, l, mid, p, c);
  } else {
    inc(t[v].r, mid + 1, r, p, c);
  }
}
void inc(int v, int p, int c) { inc(v, 1, m, p, c); }
int get(int v, int v2, int l, int r) {
  if (l == r) return l;
  if (t[v].l == -1) {
    t[v].l = t.size();
    t.push_back(Node());
  }
  if (t[v].r == -1) {
    t[v].r = t.size();
    t.push_back(Node());
  }
  if (t[v2].l == -1) {
    t[v2].l = t.size();
    t.push_back(Node());
  }
  if (t[v2].r == -1) {
    t[v2].r = t.size();
    t.push_back(Node());
  }
  int mid = (l + r) / 2;
  if (t[t[v].l].s < t[t[v2].l].s)
    return get(t[v].l, t[v2].l, l, mid);
  else
    return get(t[v].r, t[v2].r, mid + 1, r);
}
int get(int v, int v2) { return get(v, v2, 1, m); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  vector<int> root;
  set<pair<int, int> > q;
  for (int i = 0; i < n; ++i) {
    int nn;
    cin >> nn;
    root.push_back(t.size());
    t.push_back(Node());
    for (int j = 0; j < nn; ++j) {
      int p;
      cin >> p;
      inc(root.back(), p, 1);
    }
    q.insert({nn, i});
  }
  vector<pair<pair<int, int>, int> > ans;
  while (q.size() > 1) {
    auto f = (*q.begin());
    auto s = (*--q.end());
    if (s.first - f.first < 2) break;
    int temp = get(root[f.second], root[s.second]);
    inc(root[f.second], temp, 1);
    inc(root[s.second], temp, -1);
    ans.push_back({{s.second + 1, f.second + 1}, temp});
    q.erase(q.begin());
    q.erase(--q.end());
    ++f.first;
    --s.first;
    q.insert(f);
    q.insert(s);
  }
  cout << ans.size() << "\n";
  for (auto i : ans)
    cout << i.first.first << " " << i.first.second << " " << i.second << "\n";
}
