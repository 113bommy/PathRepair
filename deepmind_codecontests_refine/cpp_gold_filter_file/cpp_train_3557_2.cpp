#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
struct pair_hash {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2> &pair) const {
    return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
  }
};
int n;
vector<int> G[maxn];
unordered_map<std::pair<int, int>, int, pair_hash> mm;
int A[maxn], B[maxn], W[maxn];
int find_leaf(int i, int fa) {
  if (G[i].size() == 1) return i;
  for (auto &j : G[i]) {
    if (j != fa) return find_leaf(j, i);
  }
  return -1;
}
void f(int a, int b, int w) {
  if (a > b) swap(a, b);
  mm[make_pair(a, b)] += w;
}
void solve() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> A[i] >> B[i] >> W[i];
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }
  for (int i = 1; i < n; i++) {
    vector<int> ll, rr;
    if (G[A[i]].size() == 2 || G[B[i]].size() == 2) {
      cout << "NO" << endl;
      return;
    }
    if (G[A[i]].size() == 1) {
      ll = {A[i]};
    } else {
      for (int j = 0, cnt = 0; j < G[A[i]].size(); j++) {
        if (G[A[i]][j] != B[i]) {
          ll.push_back(find_leaf(G[A[i]][j], A[i]));
        }
      }
    }
    if (G[B[i]].size() == 1) {
      rr = {B[i]};
    } else {
      for (int j = 0; j < G[B[i]].size() && rr.size() < 2; j++) {
        if (G[B[i]][j] != A[i]) {
          rr.push_back(find_leaf(G[B[i]][j], B[i]));
        }
      }
    }
    if (rr.size() == 1) swap(ll, rr);
    if (ll.size() == 1) {
      if (rr.size() == 1) {
        f(ll[0], rr[0], W[i]);
      } else {
        f(ll[0], rr[0], W[i] / 2);
        f(ll[0], rr[1], W[i] / 2);
        f(rr[0], rr[1], -W[i] / 2);
      }
    } else {
      f(ll[0], rr[0], W[i] / 2);
      f(ll[1], rr[1], W[i] / 2);
      f(ll[0], ll[1], -W[i] / 2);
      f(rr[0], rr[1], -W[i] / 2);
    }
  }
  cout << "YES" << endl;
  cout << mm.size() << endl;
  for (auto &i : mm) {
    cout << i.first.first << ' ' << i.first.second << ' ' << i.second << endl;
  }
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  solve();
}
