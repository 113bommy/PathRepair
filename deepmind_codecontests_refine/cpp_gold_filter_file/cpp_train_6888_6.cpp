#include <bits/stdc++.h>
using namespace std;
long long n;
long long parent[1005];
vector<long long> children[1005];
long long val[1005];
map<long long, long long> adj[1005];
long long leaf[1005];
vector<long long> preorder;
bool deleted[1005];
void build(long long node) {
  preorder.push_back(node);
  for (auto& neighbor : adj[node]) {
    if (neighbor.first != parent[node]) {
      parent[neighbor.first] = node;
      val[neighbor.first] = neighbor.second;
      build(neighbor.first);
      children[node].push_back(neighbor.first);
    }
  }
}
void compleaf(long long node) {
  leaf[node] = node;
  for (long long child : children[node]) {
    compleaf(child);
    leaf[node] = leaf[child];
  }
}
void update(long long leaf, long long p, long long value) {
  while (leaf != p) {
    val[leaf] += value;
    leaf = parent[leaf];
  }
}
signed main() {
  cin >> n;
  for (long long i = 0; i < n - 1; i++) {
    long long u, v, x;
    cin >> u >> v >> x;
    u--;
    v--;
    adj[u][v] = -x;
    adj[v][u] = -x;
  }
  long long d = 0;
  set<long long> ns;
  for (long long i = 0; i < n; i++) {
    ns.insert(i);
  }
  for (long long i = 0; i < n; i++) {
    if (adj[i].size() == 2) {
      if (adj[i].begin()->second != adj[i].rbegin()->second) {
        cout << "NO\n";
        return 0;
      } else {
        long long n1 = adj[i].begin()->first, n2 = adj[i].rbegin()->first;
        long long v = adj[i].begin()->second;
        adj[n1].erase(i);
        adj[n2].erase(i);
        adj[n1][n2] += v;
        d++;
        adj[n2][n1] += v;
        ns.erase(i);
      }
    }
  }
  long long on = n;
  if (ns.size() == 2) {
    cout << "YES\n1\n"
         << *ns.begin() + 1 << ' ' << *ns.rbegin() + 1 << ' '
         << -adj[*ns.begin()].begin()->second << '\n';
    return 0;
  }
  long long root = 0;
  for (long long node : ns) {
    if (adj[node].size() == 1) {
      root = node;
      break;
    }
  }
  parent[root] = -1;
  build(root);
  compleaf(root);
  map<pair<long long, long long>, long long> ops;
  for (long long i : preorder) {
    if (i != root) {
      if (parent[i] == root) {
        long long change = -val[i];
        long long o1 = root, o2 = leaf[i];
        if (o1 > o2) {
          swap(o1, o2);
        }
        ops[{o1, o2}] += change;
        update(leaf[i], parent[i], change);
        continue;
      }
      long long change = -val[i];
      long long p = parent[i];
      long long c =
          children[p].front() != i ? children[p].front() : children[p][1];
      long long o1 = root, o2 = leaf[c];
      if (o1 > o2) {
        swap(o1, o2);
      }
      ops[{o1, o2}] += -change / 2;
      o1 = root, o2 = leaf[i];
      if (o1 > o2) {
        swap(o1, o2);
      }
      ops[{o1, o2}] += change / 2;
      o1 = leaf[i], o2 = leaf[c];
      if (o1 > o2) {
        swap(o1, o2);
      }
      ops[{o1, o2}] += change / 2;
      update(leaf[i], parent[i], change);
    }
  }
  for (auto it = ops.begin(); it != ops.end(); ++it) {
    if (it->first.first == it->first.second) {
      ops.erase(it);
    }
  }
  cout << "YES\n" << ops.size() << '\n';
  for (auto& op : ops) {
    cout << op.first.first + 1 << ' ' << op.first.second + 1 << ' ' << op.second
         << '\n';
  }
}
