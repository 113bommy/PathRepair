#include <bits/stdc++.h>
using namespace std;
const int bits = 1000;
bitset<bits> node[4 * 100060];
long long int leftOver[4 * 100060];
int n;
int treeSize[100060];
vector<int> adj[100060];
int dfsOrder[100060];
int o = 1;
void dfs(int curr = 1, int par = -1) {
  treeSize[curr] = 1;
  dfsOrder[curr] = o++;
  for (int nxt : adj[curr]) {
    if (nxt != par) {
      dfs(nxt, curr);
      treeSize[curr] += treeSize[nxt];
    }
  }
}
int m;
bitset<bits> rotate(std::bitset<bits> b, unsigned k) {
  b = b << (k) | b >> (bits - (k));
  b = b | (b >> m);
  return b;
}
void build(int pos, int bit, int id = 1, int l = 1, int r = n) {
  if (l == r) {
    node[id][bit] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid)
    build(pos, bit, id << 1, l, mid);
  else
    build(pos, bit, (id << 1) + 1, mid + 1, r);
  node[id] = node[id << 1] | node[(id << 1) + 1];
}
void push(int id) {
  if (leftOver[id] > 0) {
    leftOver[id << 1] = (leftOver[id] + leftOver[id << 1]) % m;
    leftOver[(id << 1) + 1] = (leftOver[id] + leftOver[(id << 1) + 1]) % m;
    leftOver[id] = 0;
  }
}
void add(int val, int L, int R, int id = 1, int l = 1, int r = n) {
  if (L <= l && r <= R) {
    leftOver[id] = (leftOver[id] + val) % m;
    return;
  }
  push(id);
  int mid = (l + r) >> 1;
  if (L <= mid) add(val, L, R, id << 1, l, mid);
  if (R > mid) add(val, L, R, (id << 1) + 1, mid + 1, r);
  node[id] = rotate(node[id << 1], leftOver[id << 1]) |
             rotate(node[(id << 1) + 1], leftOver[(id << 1) + 1]);
}
bitset<bits> ans;
void query(int qL, int qR, int id = 1, int l = 1, int r = n) {
  if (qL <= l && qR >= r) {
    ans = ans | rotate(node[id], leftOver[id]);
    return;
  }
  push(id);
  int mid = (l + r) >> 1;
  if (qL <= mid) query(qL, qR, id << 1, l, mid);
  if (qR > mid) query(qL, qR, (id << 1) + 1, mid + 1, r);
  node[id] = rotate(node[id << 1], leftOver[id << 1]) |
             rotate(node[(id << 1) + 1], leftOver[(id << 1) + 1]);
}
vector<int> primes;
vector<int> sieve(int limit) {
  vector<int> primes;
  bool in[limit + 1];
  memset(in, true, sizeof(in));
  for (int i = 2; i <= limit; i++) {
    if (in[i]) {
      primes.push_back(i);
      for (int j = i; j <= limit; j += i) in[j] = false;
    }
  }
  return primes;
}
int a[100060];
int aTemp[100060];
int addBrute(int l, int r, int x) {
  for (int i = l; i < r + 1; i++) a[i] = (a[i] + x) % m;
}
bitset<bits> findBrute(int l, int r) {
  bitset<bits> temp = 0;
  for (int i = l; i < r + 1; i++) temp[a[i] % m] = 1;
  return temp;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> n >> m;
  primes = sieve(m);
  for (int i = 0; i < n; i++) cin >> a[i + 1];
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs();
  for (int i = 0; i < n; i++) {
    build(dfsOrder[i + 1], a[i + 1] % m);
  }
  for (int i = 1; i < n + 1; i++) {
    aTemp[dfsOrder[i]] = a[i];
  }
  for (int i = 1; i < n + 1; i++) {
    a[i] = aTemp[i];
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    int t, v;
    cin >> t >> v;
    if (t == 1) {
      int x;
      cin >> x;
      add(x % m, dfsOrder[v], dfsOrder[v] + treeSize[v] - 1);
    } else {
      ans = 0;
      query(dfsOrder[v], dfsOrder[v] + treeSize[v] - 1);
      int k = 0;
      for (int j = 0; j < primes.size(); j++) {
        if (primes[j] < m) {
          if (ans[primes[j]]) {
            k++;
          }
        }
      }
      cout << k << "\n";
    }
  }
  return 0;
}
