#include <bits/stdc++.h>
using namespace std;
class SegmentTree {
  vector<int> segtree;
  int inf;

 public:
  SegmentTree(int size) {
    inf = 1e5;
    segtree.resize(4 * size, inf);
  }
  void update(int u, int a, int b, int i, int j, int x) {
    if (j < a || i > b || a > b) return;
    if (j >= b && i <= a) {
      segtree[u] = x;
      return;
    }
    update(u * 2, a, (a + b) / 2, i, j, x);
    update(u * 2 + 1, (a + b) / 2 + 1, b, i, j, x);
    segtree[u] = min(segtree[u * 2], segtree[u * 2 + 1]);
  }
  void update(int i, int x) { update(1, 0, segtree.size() / 4 - 1, i, i, x); }
  int query(int u, int a, int b, int i, int j) {
    if (j < a || i > b || a > b) return inf;
    if (j >= b && i <= a) return segtree[u];
    return min(query(u * 2, a, (a + b) / 2, i, j),
               query(u * 2 + 1, 1 + (a + b) / 2, b, i, j));
  }
  int query(int i, int j) { return query(1, 0, segtree.size() / 4 - 1, i, j); }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  for (cin >> T; T--;) {
    int n, m;
    cin >> n >> m;
    vector<string> s(n + 2);
    vector<SegmentTree> horizontal(n + 2, SegmentTree(m + 2));
    vector<SegmentTree> vertical(m + 2, SegmentTree(n + 2));
    set<int, greater<int>> exists;
    vector<int> up(26, 4005), left(26, 4005);
    vector<int> down(26, -4005), right(26, -4005);
    for (int i = 1; i <= n; ++i) {
      cin >> s[i];
      s[i] = '.' + s[i];
    }
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        if (s[i][j] != '.') {
          int ch = s[i][j] - 'a';
          exists.insert(ch);
          horizontal[i].update(j, ch);
          vertical[j].update(i, ch);
          up[ch] = min(up[ch], i);
          down[ch] = max(down[ch], i);
          left[ch] = min(left[ch], j);
          right[ch] = max(right[ch], j);
        } else {
          horizontal[i].update(j, -1);
          vertical[j].update(i, -1);
        }
    if (!exists.size()) {
      cout << "YES\n0\n";
      goto end;
    }
    for (auto i : exists) {
      if (up[i] != down[i] && left[i] != right[i]) {
        cout << "NO\n";
        goto end;
      } else if (up[i] == down[i]) {
        if (horizontal[up[i]].query(left[i], right[i]) < i) {
          cout << "NO\n";
          goto end;
        }
      } else {
        if (vertical[left[i]].query(up[i], down[i]) < i) {
          cout << "NO\n";
          goto end;
        }
      }
    }
    cout << "YES\n" << *exists.begin() + 1 << '\n';
    for (int i = 0; i <= *exists.begin(); ++i)
      if (exists.count(i))
        cout << up[i] << ' ' << left[i] << ' ' << down[i] << ' ' << right[i]
             << '\n';
      else
        cout << up[*exists.begin()] << ' ' << left[*exists.begin()] << ' '
             << up[*exists.begin()] << ' ' << left[*exists.begin()] << '\n';
  end:;
  }
}
