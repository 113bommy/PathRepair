#include <bits/stdc++.h>
using namespace std;
template <typename T>
int len(const T& a) {
  return a.size();
}
using ll = long long;
constexpr int N = 2e5 + 10;
struct Node {
  Node* left = nullptr;
  Node* right = nullptr;
} trie[N];
Node* last = trie;
int n;
int a[N];
int rm;
void Insert(int val) {
  Node* j = trie;
  for (int i = 30; i >= 0; --i) {
    if ((val >> i) & 1) {
      if (!j->right) j->right = last++;
      j = j->right;
    } else {
      if (!j->left) j->left = last++;
      j = j->left;
    }
  }
}
int Get(Node* c) {
  int l = 0, r = 0;
  if (c->left) l = Get(c->left);
  if (c->right) r = Get(c->right);
  if (l >= 2 && r >= 2) {
    rm += min(r - 1, l - 1);
    return r + l - min(r - 1, l - 2);
  }
  if (!c->right && !c->left) ++l;
  return r + l;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  ++last;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    Insert(a[i]);
  }
  Get(trie);
  cout << rm;
  return 0;
}
