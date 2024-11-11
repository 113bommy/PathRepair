#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
vector<vector<int>> divisorsAll(int n) {
  vector<vector<int>> res(n + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; j += i) {
      res[j].push_back(i);
    }
  }
  return res;
}
const int LEN = 17;
const int MA = 100005;
struct Node {
  int mi;
  shared_ptr<Node> c[2];
  Node() : mi(INT_MAX / 2), c{nullptr, nullptr} {}
};
shared_ptr<Node> ROOT[MA];
void put(int u, int d) {
  auto node = ROOT[d];
  (node->mi) = min((node->mi), (u));
  for (int a = LEN - 1; a >= 0; --a) {
    int b = u >> a & 1;
    if (node->c[b] == nullptr) {
      node->c[b] = make_shared<Node>();
    }
    node = node->c[b];
    (node->mi) = min((node->mi), (u));
  }
}
int get(int x, int k, int s) {
  auto node = ROOT[k];
  if (k % x || x + node->mi > s) return -1;
  int re = 0;
  for (int a = LEN - 1; a >= 0; --a) {
    int b = 1 - (x >> a & 1);
    auto ne = node->c[b];
    if (ne == nullptr || x + ne->mi > s) {
      b = 1 - b;
    }
    re |= b << a;
    node = node->c[b];
  }
  return re;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(20);
  auto D = divisorsAll(MA);
  for (int(a) = (0); (a) < (int)(MA); ++(a)) ROOT[a] = make_shared<Node>();
  int Q;
  cin >> Q;
  for (int(q) = (0); (q) < (int)(Q); ++(q)) {
    int T;
    cin >> T;
    if (T == 1) {
      int u;
      cin >> u;
      for (auto &(d) : (D[u])) {
        put(u, d);
      }
    } else {
      int x, k, s;
      cin >> x >> k >> s;
      int re = get(x, k, s);
      cout << re << endl;
    }
  }
}
