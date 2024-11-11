#include <bits/stdc++.h>
using namespace std;
int binarySearch(long long int arr[], int left, int right, long long int x,
                 bool is_left = false) {
  if (!is_left) {
    while (left < right) {
      int mid = (left + right) / 2;
      if (x < arr[mid])
        right = mid;
      else
        left = mid + 1;
    }
    return left;
  } else {
    while (left < right) {
      int mid = (left + right) / 2;
      if (x <= arr[mid])
        right = mid;
      else
        left = mid + 1;
    }
    return left;
  }
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int modInverse(int a, int m) {
  a = a % m;
  for (int x = 1; x < m; x++)
    if ((a * x) % m == 1) return x;
}
template <typename K, typename V>
multimap<V, K> sortMap(std::map<K, V> const &map) {
  std::multimap<V, K> multimap;
  for (auto const &pair : map) {
    multimap.insert(std::make_pair(pair.second, pair.first));
  }
  return multimap;
}
string reverseStr(string str) {
  string result = str;
  int n = str.length();
  for (int i = 0; i < n / 2; i++) swap(result[i], result[n - i - 1]);
  return result;
}
int parent[1000001];
int depth[1000001];
void make_set(int v) {
  parent[v] = v;
  depth[v] = 0;
}
int find_set(int v) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (depth[a] < depth[b]) swap(a, b);
    parent[b] = a;
    if (depth[a] == depth[b]) ++depth[a];
  }
}
int tree[32];
void build(int a[], int v, int left, int right) {
  if (left == right)
    tree[v] = a[left];
  else {
    int tm = (left + right) / 2;
    build(a, v * 2, left, tm);
    build(a, v * 2 + 1, tm + 1, right);
    tree[v] = tree[v * 2] + tree[v * 2 + 1];
  }
}
int sum(int v, int left, int right, int l, int r) {
  if (l > r) return 0;
  if (l == left && r == right) return tree[v];
  int tm = (left + right) / 2;
  return sum(v * 2, left, tm, l, min(r, tm)) +
         sum(v * 2 + 1, tm + 1, right, max(l, tm + 1), r);
}
void update(int v, int left, int right, int pos, int new_val) {
  if (left == right)
    tree[v] = new_val;
  else {
    int tm = (left + right) / 2;
    if (pos <= tm)
      update(v * 2, left, tm, pos, new_val);
    else
      update(v * 2 + 1, tm + 1, right, pos, new_val);
    tree[v] = tree[v * 2] + tree[v * 2 + 1];
  }
}
void bfs(vector<int> g[], bool used[]) {
  queue<int> queue;
  queue.push(1);
  used[1] = true;
  while (!queue.empty()) {
    int u = queue.front();
    queue.pop();
    for (size_t i = 0; i < g[u].size(); ++i) {
      int u = g[u][i];
      if (!used[u]) {
        used[u] = true;
        queue.push(u);
      }
    }
  }
}
int binpow(int a, int n) {
  int res = 1;
  while (n) {
    if (n & 1) res *= a;
    a *= a;
    n >>= 1;
  }
  return res;
}
void reverse(int arr[], int n) {
  for (int i = 0; i < n / 2; i++) swap(arr[i], arr[n - 1 - i]);
}
vector<int> cifar(long long int n) {
  vector<int> ans;
  while (n) {
    ans.push_back(n % 10);
    n = n / 10;
  }
  for (int i = 0; i < ans.size() / 2; i++)
    swap(ans[i], ans[ans.size() - 1 - i]);
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int n;
  cin >> n;
  if (n == 1)
    cout << 8 << ' ' << 9 << endl;
  else
    cout << 2 * n << ' ' << 3 * n << endl;
}
