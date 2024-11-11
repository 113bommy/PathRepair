#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  while (a != 0 && b != 0) {
    if (a < b) swap(a, b);
    a = a % b;
  }
  return b;
}
struct Node {
  unordered_map<char, Node*> nexts;
};
Node* root = new Node();
void add(Node* root, string s) {
  Node* cur = root;
  for (int i = 0; i < s.length(); i++) {
    if (cur->nexts[s[i]] == nullptr) cur->nexts[s[i]] = new Node();
    cur = cur->nexts[s[i]];
  }
}
long long mod = 1000000007;
long long powerFast(long long num, long long deg) {
  long long result = 1;
  while (deg) {
    if (deg % 2 == 0) {
      deg /= 2;
      num = (num * num) % mod;
    } else {
      deg--;
      result = (num * result) % mod;
    }
  }
  return result;
}
bool bch(int x, int i) { return bool((1 << i) & x); }
bool check(int k, int j, int n) {
  for (int i = 0; i < n - 1; i++) {
    int tmp = bch(k, i) + bch(k, i + 1) + bch(j, i) + bch(j, i + 1);
    if (tmp == 4 || tmp == 0) {
      return 0;
    }
  }
  return 1;
}
int siz[100000];
int parent[100000];
int find_set(int v) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
  parent[v] = v;
  siz[v] = 1;
}
void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (siz[a] < siz[b]) swap(a, b);
    parent[b] = a;
    siz[a] += siz[b];
  }
}
double dist(pair<int, int> a, pair<int, int> b) {
  return sqrt((a.first - b.first) * (a.first - b.first) +
              (a.second - b.second) * (a.second - b.second));
}
vector<int> z_func(string s) {
  vector<int> z(s.length());
  int l = 0, r = 0;
  z[0] = s.length();
  for (int i = 1; i < s.length(); i++) {
    z[i] = max(0, min(z[i - l], r - i));
    while (i + z[i] < s.length() && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}
vector<int> prefix_function(string s) {
  int n = (int)s.length();
  vector<int> pi(n);
  for (int i = 1; i < n; ++i) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) ++j;
    pi[i] = j;
  }
  return pi;
}
int main() {
  long long n, d, m;
  cin >> n >> d >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    if (x <= n && y <= n) {
      if (x + y < d || x + (n - y) < n - d || (n - x) + (n - y) < d ||
          n - x + y < n - d) {
        cout << "NO\n";
      } else
        cout << "YES\n";
    } else
      cout << "NO\n";
  }
}
