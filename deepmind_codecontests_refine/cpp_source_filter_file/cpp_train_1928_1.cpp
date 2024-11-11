#include <bits/stdc++.h>
using namespace std;
int n, m, k;
string s;
char arb[4 * 200010];
char c, ans, p[20];
int ppos[20];
int l, r, pos;
int cnt[20][20];
set<int> S;
void lazyUpdate(int node, int left, int right) {
  if (!arb[node]) return;
  if (left != right) {
    arb[node << 1] = arb[node];
    arb[(node << 1) + 1] = arb[node];
    arb[node] = 0;
  }
}
void update(int node, int left, int right) {
  lazyUpdate(node, left, right);
  if (l <= left && right <= r) {
    arb[node] = c;
    lazyUpdate(node, left, right);
    return;
  }
  int mid = (left + right) / 2;
  if (l <= mid) update(node << 1, left, mid);
  if (r > mid) update((node << 1) + 1, mid + 1, right);
}
void query(int node, int left, int right) {
  lazyUpdate(node, left, right);
  if (left == right) {
    ans = arb[node];
    return;
  }
  int mid = (left + right) / 2;
  if (pos <= mid)
    query(node << 1, left, mid);
  else
    query((node << 1) + 1, mid + 1, right);
}
void createTree(int node, int left, int right) {
  if (left == right) {
    arb[node] = s[left];
    return;
  }
  int mid = (left + right) / 2;
  createTree(node << 1, left, mid);
  createTree((node << 1) + 1, mid + 1, right);
}
char query(int where) {
  pos = where;
  query(1, 1, n);
  return ans;
}
int main() {
  cin >> n >> m >> k;
  cin >> s;
  s = "*" + s;
  createTree(1, 1, n);
  for (int i = 1; i < n; ++i) {
    if (s[i] != s[i + 1]) {
      cnt[s[i] - 'a'][s[i + 1] - 'a']++;
      S.insert(i);
    }
  }
  for (int i = 1; i <= m; ++i) {
    int op;
    cin >> op;
    if (op == 1) {
      cin >> l >> r >> c;
      vector<int> toErase;
      set<int>::iterator it = S.lower_bound(l);
      while (it != S.end() && *it < r) {
        cnt[query(*it) - 'a'][query(*it + 1) - 'a']--;
        toErase.push_back(*it);
        ++it;
      }
      if (l != 1) {
        char c1, c2;
        c1 = query(l - 1);
        c2 = query(l);
        cnt[c1 - 'a'][c2 - 'a']--;
        if (c1 != c2) S.erase(l - 1);
        cnt[c1 - 'a'][c - 'a']++;
        if (c1 != c) S.insert(l - 1);
      }
      if (r != n) {
        char c1, c2;
        c1 = query(r);
        c2 = query(r + 1);
        cnt[c1 - 'a'][c2 - 'a']--;
        if (c1 != c2) S.erase(r);
        cnt[c - 'a'][c2 - 'a']++;
        if (c != c2) S.insert(r);
      }
      for (int i = 0; i < toErase.size(); ++i) {
        S.erase(toErase[i]);
      }
      update(1, 1, n);
    } else {
      cin >> p;
      for (int i = 0; i < k; ++i) {
        ppos[p[i] - 'a'] = i;
      }
      int rez = 0;
      for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
          if (ppos[i] < ppos[j]) {
            rez += cnt[i][j];
          }
        }
      }
      rez += n - S.size();
      cout << rez << "\n";
    }
  }
}
