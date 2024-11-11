#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dout() { cerr << endl; }
template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
  cerr << H << ' ';
  dout(T...);
}
struct Node {
  Node* left = nullptr;
  Node* right = nullptr;
  Node(Node* l = nullptr, Node* r = nullptr) : left(l), right(r) {}
};
Node* root = new Node;
void insert(ll x) {
  Node* cur = root;
  for (int i = 39; i >= 0; i--) {
    if (((1LL << i) & x) == 0) {
      if (!cur->left) cur->left = new Node;
      cur = cur->left;
    } else {
      if (!cur->right) cur->right = new Node;
      cur = cur->right;
    }
  }
}
ll max_xor(ll x) {
  Node* cur = root;
  ll res = 0;
  for (int i = 39; i >= 0; i--) {
    if (((1LL << i) & x) == 0) {
      if (cur->right) {
        res ^= 1LL << i;
        cur = cur->right;
      } else {
        cur = cur->left;
      }
    } else {
      if (cur->left) {
        res ^= 1LL << i;
        cur = cur->left;
      } else {
        cur = cur->right;
      }
    }
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<ll> p(n);
  p[0] = a[0];
  for (int i = 1; i < n; i++) {
    p[i] = p[i - 1] ^ a[i];
  }
  ll total_xor = p.back();
  ll res = total_xor;
  insert(0);
  for (int i = 0; i < n; i++) {
    res = max(res, max_xor(total_xor ^ p[i]));
    insert(p[i]);
  }
  cout << res;
  return 0;
}
