#include <bits/stdc++.h>
using namespace std;
int st[200010][30];
int nxt[200010];
vector<int> go[200010];
int arr[200010];
vector<int>::iterator it;
int st2[200010][30];
int main() {
  int n, m, q, prev, cur;
  cin >> n >> m >> q;
  cin >> prev;
  int beg = prev;
  for (int i = 0; i < 200005; i++) {
    for (int j = 0; j < 28; j++) st[i][j] = st2[i][j] = INT_MAX;
  }
  for (int i = 1; i < n; ++i) {
    cin >> cur;
    nxt[prev] = cur;
    prev = cur;
  }
  nxt[cur] = beg;
  for (int i = 0; i < m; ++i) {
    cin >> cur;
    arr[i] = cur;
    go[cur].push_back(i);
  }
  for (int i = 0; i < m; ++i) {
    if (go[nxt[arr[i]]].size() == 0) continue;
    it = upper_bound(go[nxt[arr[i]]].begin(), go[nxt[arr[i]]].end(), i);
    int id = it - go[nxt[arr[i]]].begin();
    if (id >= go[nxt[arr[i]]].size()) continue;
    st[i][0] = go[nxt[arr[i]]][id];
  }
  for (int i = m - 1; i >= 0; --i) {
    for (int j = 1; j <= 25; ++j) {
      if (st[i][j - 1] != INT_MAX) st[i][j] = st[st[i][j - 1]][j - 1];
    }
  }
  for (int i = m - 1; i >= 0; --i) {
    int node = i;
    for (int j = 25; j >= 0; --j) {
      if ((n - 1) & (1 << j)) {
        node = st[node][j];
        if (node == INT_MAX) break;
      }
    }
    if (node == INT_MAX) continue;
    st2[i][0] = node;
  }
  for (int i = m - 1; i >= 0; --i) {
    for (int j = 1; j <= 25; ++j) {
      if ((i + (1 << (j - 1))) <= m - 1)
        st2[i][j] = min(st2[i][j - 1], st2[i + (1 << (j - 1))][j - 1]);
    }
  }
  for (int i = 0; i < q; ++i) {
    cin >> prev >> cur;
    prev--;
    cur--;
    int dist = cur - prev + 1;
    int node = prev;
    int mn = INT_MAX;
    for (int j = 25; j >= 0; --j) {
      if (dist & (1 << j)) {
        mn = min(mn, st2[node][j]);
        node = node + (1 << (j));
        if (node >= m) break;
      }
    }
    if (mn <= cur)
      cout << '1';
    else
      cout << '0';
  }
}
