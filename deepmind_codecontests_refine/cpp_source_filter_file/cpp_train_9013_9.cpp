#include <bits/stdc++.h>
using namespace std;
void read(vector<int>& c, int size) {
  for (int i = 0; i < size; i++) {
    int q;
    scanf("%d", &q);
    c.push_back(q);
  }
}
void read(vector<pair<int, int> >& c, int size) {
  for (int i = 0; i < size; i++) {
    int q;
    int r;
    scanf("%d", &q);
    scanf("%d", &r);
    c.push_back(make_pair(q, r));
  }
}
void print(vector<int>& coeffs) {
  for (int i = 0; i < coeffs.size(); i++) {
    cout << coeffs[i] << " ";
  }
  cout << endl;
}
int op(int a, int b, int& l) {
  if (l % 2 == 0) {
    l++;
    return a + b;
  }
  if (l % 2 == 1) {
    l++;
    return a - b;
  }
}
int power(int a, int b) {
  if (b == 0) {
    return 1;
  } else {
    int q = power(a, b / 2);
    int r = (q * q) % 1000000007;
    if (b % 2) {
      return (r * a) % 1000000007;
    } else {
      return r;
    }
  }
}
int inv(int a) { return power(a, 1000000007 - 2); }
bool input() {
  string q;
  cin >> q;
  return (q == "TAK");
}
int print(int q, int l, int r) {
  cout << q << " " << l << " " << r << endl;
  fflush(stdout);
  if (q == 1) {
    return input();
  }
  return -1;
}
int bs(int l, int r) {
  while (l < r) {
    int mid = (l + r) / 2;
    int q = print(1, mid, mid + 1);
    if (q == 1) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return l;
}
void dfs(int node, vector<vector<int> >& adj, vector<vector<int> >& q,
         map<int, int>& color, vector<bool>& visited) {
  if (!visited[node]) {
    visited[node] = true;
    int i;
    int sz = q[node].size();
    set<int> f;
    for (int i = 1; i <= sz; i++) {
      f.insert(i);
    }
    for (auto& p : q[node]) {
      if (color.find(p) != color.end()) {
        f.erase(color[p]);
      }
    }
    for (auto& p : q[node]) {
      if (color.find(p) == color.end()) {
        int v = (*f.begin());
        f.erase(v);
        color[p] = v;
      }
    }
    for (i = 0; i < adj[node].size(); i++) {
      dfs(adj[node][i], adj, q, color, visited);
    }
  }
}
int main() {
  int m, n;
  int k, f;
  int l, r;
  int i, j;
  vector<int> a;
  cin >> n >> m;
  vector<vector<int> > q(n + 1);
  vector<vector<int> > adj(n + 1);
  int p = 0;
  for (i = 1; i <= n; i++) {
    int r;
    cin >> r;
    p = max(p, r);
    read(q[i], r);
  }
  for (i = 0; i < n - 1; i++) {
    int l1;
    int l2;
    cin >> l1 >> l2;
    adj[l1].push_back(l2);
    adj[l2].push_back(l1);
  }
  map<int, int> color;
  vector<bool> visited(n + 1, false);
  dfs(1, adj, q, color, visited);
  cout << p << endl;
  for (i = 1; i <= m; i++) {
    if (color.find(i) != color.end()) {
      cout << color[i] << " ";
    } else {
      cout << 1 << " ";
    }
  }
  cout << endl;
}
