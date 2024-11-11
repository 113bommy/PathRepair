#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
vector<int> circuit;
vector<int> e[MAXN];
void calc(int v) {
  stack<int> s;
  while (true) {
    if (((int)e[v].size()) == 0) {
      circuit.push_back(v);
      if (!((int)s.size())) {
        break;
      }
      v = s.top();
      s.pop();
    } else {
      s.push(v);
      int u = e[v].back();
      e[v].pop_back();
      v = u;
    }
  }
}
int a[MAXN];
int b[MAXN];
int c[MAXN];
vector<int> comp;
unordered_map<int, int> act;
unordered_map<long long, vector<int> > pos;
bool bio[MAXN];
void dfs(int v) {
  if (bio[v]) return;
  bio[v] = true;
  for (auto w : e[v]) {
    dfs(w);
  }
}
vector<vector<int> > ans;
vector<vector<int> > sol;
int s;
void solve(vector<int> &start) {
  int uk = 0;
  for (auto x : start) {
    calc(x);
    uk += ((int)circuit.size()) - 1;
    reverse(circuit.begin(), circuit.end());
    ans.push_back(circuit);
    circuit.clear();
  }
  if (uk > s) {
    cout << -1;
    exit(0);
  }
  for (auto v : ans) {
    vector<int> nv;
    for (int i = 0; i < ((int)v.size()) - 1; ++i) {
      int x = v[i];
      int y = v[i + 1];
      assert(((int)pos[(long long)x * MAXN + y].size()) > 0);
      nv.push_back(pos[(long long)x * MAXN + y].back());
      pos[(long long)x * MAXN + y].pop_back();
    }
    sol.push_back(nv);
  }
}
int main() {
  int n;
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    comp.push_back(a[i]);
  }
  sort(comp.begin(), comp.end());
  comp.erase(unique(comp.begin(), comp.end()), comp.end());
  for (int i = 0; i < ((int)comp.size()); ++i) {
    act[comp[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    a[i] = act[a[i]];
    b[i] = a[i];
  }
  sort(b, b + n);
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      e[b[i]].push_back(a[i]);
      pos[(long long)b[i] * MAXN + a[i]].push_back(i);
    }
  }
  vector<int> start;
  for (int i = 0; i < n; ++i) {
    if (!bio[b[i]] && ((int)e[b[i]].size())) {
      dfs(b[i]);
      start.push_back(b[i]);
    }
  }
  if (((int)start.size()) <= 2) {
    solve(start);
  } else {
    int uk = 0;
    for (auto x : start) {
      calc(x);
      uk += ((int)circuit.size()) - 1;
      circuit.clear();
    }
    if (uk > s) {
      cout << -1;
      return 0;
    }
    for (int i = 0; i < n; ++i) {
      e[i].clear();
    }
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) {
        e[b[i]].push_back(a[i]);
      }
    }
    int can = s - uk;
    can = min(((int)start.size()), can);
    vector<int> out;
    for (int i = 0; i < can; ++i) {
      int x = start[((int)start.size()) - i - 1];
      out.push_back(pos[(long long)x * MAXN + e[x].back()].back());
    }
    if (((int)out.size()) > 1) {
      sol.push_back(out);
    }
    for (int i = 0; i < can - 1; ++i) start.pop_back();
    for (int i = 0; i < n; ++i) {
      c[i] = a[i];
    }
    for (int i = 0; i < n; ++i) e[i].clear();
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) {
        pos[(long long)b[i] * MAXN + a[i]].pop_back();
      }
    }
    for (int i = 0; i < ((int)out.size()); ++i) {
      c[out[(i + 1) % ((int)out.size())]] = a[out[i]];
    }
    for (int i = 0; i < n; ++i) {
      if (c[i] != b[i]) {
        e[b[i]].push_back(c[i]);
        pos[(long long)b[i] * MAXN + c[i]].push_back(i);
      }
    }
    solve(start);
  }
  cout << ((int)sol.size()) << endl;
  for (auto v : sol) {
    cout << ((int)v.size()) << "\n";
    for (auto x : v) cout << x + 1 << " ";
    cout << "\n";
  }
}
