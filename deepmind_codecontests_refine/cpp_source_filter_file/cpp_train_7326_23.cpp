#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 8;
vector<bool> x;
struct trie {
  bool finish;
  trie *c0, *c1;
  trie() {
    c1 = NULL;
    c0 = NULL;
    finish = 0;
  }
  inline void add_num() {
    if (x.size() == 0) {
      finish = 1;
      return;
    }
    if (x[x.size() - 1]) {
      x.pop_back();
      if (c1 == NULL) c1 = new trie();
      c1->add_num();
    } else {
      x.pop_back();
      if (c0 == NULL) c0 = new trie();
      c0->add_num();
    }
  }
  inline long long Search(long long cur = 0) {
    if (c0 == NULL && c1 == NULL) return cur;
    bool now = x[x.size() - 1];
    x.pop_back();
    if (now == 1) {
      if (c0 != NULL) return c0->Search(cur * 2);
      return c1->Search(cur * 2 + 1);
    } else {
      if (c1 != NULL) return c1->Search(cur * 2 + 1);
      return c0->Search(cur * 2);
    }
  }
};
long long a[maxn];
inline void F(long long X) {
  while (x.size()) x.pop_back();
  for (long long i = 0; i <= 40; i++, X /= 2) x.push_back(X & 1);
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  trie *root = new trie();
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long X = a[1];
  for (int i = 1; i <= n; i++, (X ^= a[i])) {
    F(X);
    root->add_num();
  }
  long long ans = 0;
  X = a[n];
  for (int i = n; i >= 1; i--, X ^= a[i]) {
    F(X);
    ans = max(ans, X ^ (root->Search()));
  }
  cout << ans;
  return 0;
}
