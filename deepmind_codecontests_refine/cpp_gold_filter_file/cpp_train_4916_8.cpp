#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;
using li = pair<ll, int>;
const int MAXK = 5000;
struct jump {
  int node, prime, count;
};
int n;
vector<int> k;
int fact_node[MAXK + 1];
vector<map<int, ii>> children;
vector<int> primes;
bool not_prime[MAXK + 1];
int node_count = 0;
vector<vector<ii>> adjl;
vector<int> deg;
vector<ll> cost;
vector<int> cnt;
vector<bool> active;
int active_nodes;
void fill_primes() {
  for (int i = 2; i < MAXK; ++i) {
    if (not_prime[i]) continue;
    primes.push_back(i);
    for (int j = i * i; j < MAXK; j += i) {
      not_prime[j] = true;
    }
  }
}
int add_node() {
  children.emplace_back();
  return node_count++;
}
void get_factors(int x, vector<ii> &factors) {
  int pi = 0;
  while (x > 1) {
    if (pi == factors.size()) factors.emplace_back(primes[pi], 0);
    while (x % primes[pi] == 0) {
      factors[pi].second++;
      x /= primes[pi];
    }
    ++pi;
  }
}
void build_tree() {
  fill_primes();
  queue<jump> q;
  fact_node[0] = fact_node[1] = add_node();
  q.push({0, 0, 0});
  vector<ii> factors;
  for (int i = 2; i <= MAXK; ++i) {
    get_factors(i, factors);
    while (q.front().node) q.pop();
    int fi = factors.size() - 1;
    while (q.front().prime) {
      if (q.front().prime != factors[fi].first) break;
      if (q.front().count != factors[fi].second) break;
      q.push(q.front());
      q.pop();
      --fi;
    }
    int node = q.front().node;
    if (q.front().prime == factors[fi].first) {
      int last_node = q.front().node;
      int prime = factors[fi].first;
      int to_add = factors[fi].second - q.front().count;
      int child = children[last_node][prime].second;
      int new_child = add_node();
      children[child][prime] = ii(to_add, new_child);
      q.push({node, prime, factors[fi].second});
      node = new_child;
      --fi;
    }
    q.pop();
    while (fi >= 0) {
      int prime = factors[fi].first;
      int count = factors[fi].second;
      int new_child = add_node();
      children[node][prime] = ii(count, new_child);
      q.push({node, prime, count});
      node = new_child;
      --fi;
    }
    q.push({node, 0, 0});
    fact_node[i] = node;
  }
}
void visit(int node) {
  for (auto it : children[node]) {
    int weight = it.second.first;
    int child = it.second.second;
    adjl[node].emplace_back(child, weight);
    adjl[child].emplace_back(node, weight);
    ++deg[node];
    ++deg[child];
    visit(child);
  }
}
void build_graph() {
  adjl.resize(node_count);
  deg.resize(node_count, 0);
  active.resize(node_count, true);
  cost.resize(node_count, 0LL);
  cnt.resize(node_count, 0);
  active_nodes = node_count;
  for (auto it : k) {
    ++cnt[fact_node[it]];
  }
  visit(0);
}
ii get_active_neigh(int node) {
  for (auto it : adjl[node]) {
    if (active[it.first]) {
      return it;
    }
  }
}
ll solve() {
  priority_queue<ii> pq;
  for (int i = 0; i < node_count; ++i) {
    if (deg[i] == 1) {
      pq.push({-cnt[i], i});
    }
  }
  while (!pq.empty()) {
    ii cur = pq.top();
    pq.pop();
    int node = cur.second;
    if (!deg[node]) return cost[node];
    active[node] = false;
    --active_nodes;
    ii edge = get_active_neigh(node);
    int neigh = edge.first;
    ll new_cost = -(ll)cur.first * edge.second;
    cnt[neigh] += cnt[node];
    cost[neigh] += cost[node] + new_cost;
    if (--deg[neigh] == 1) {
      edge = get_active_neigh(neigh);
      pq.push({-cnt[neigh], neigh});
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  k.resize(n);
  for (int i = 0; i < n; ++i) cin >> k[i];
  build_tree();
  build_graph();
  cout << solve() << "\n";
  return 0;
}
