#include <bits/stdc++.h>
using namespace std;
int n;
struct Trie {
  int trie[2000005][2];
  int cnt[2000005];
  int root = 0;
  long long val[2000005];
  long long xorsum = 0;
  long long ans[2000005];
  int C = 0;
  int newroot() {
    trie[C][0] = trie[C][1] = -1;
    cnt[C] = 0;
    return C++;
  }
  void Insert(long long x) {
    long long p = root;
    for (int i = 60; i >= 0; i--) {
      long long id = (x >> i) & 1;
      if (trie[p][id] == -1) trie[p][id] = newroot();
      p = trie[p][id];
      cnt[p]++;
    }
    val[p] = x;
  }
  bool check(long long xorsum, long long &res, int index, bool limit, int dep) {
    if (index != root && (cnt[index] == 0 || index == -1)) return false;
    if (dep == -1) {
      res = val[index];
      cnt[index]--;
      return true;
    }
    int id = (xorsum >> dep) & 1;
    if (id == 0) {
      bool ret = (check(xorsum, res, trie[index][0], limit, dep - 1)) ||
                 (!limit && check(xorsum, res, trie[index][1], limit, dep - 1));
      if (ret == 0) return false;
      cnt[index]--;
      return true;
    } else {
      bool ret = (check(xorsum, res, trie[index][0], limit, dep - 1)) ||
                 (check(xorsum, res, trie[index][1], false, dep - 1));
      if (ret == 0) return false;
      cnt[index]--;
      return true;
    }
  }
  void solve() {
    for (int i = n - 1; i >= 0; i--) {
      long long res;
      bool ret = check(xorsum, res, root, true, 60);
      if (ret == 0) {
        puts("No");
        return;
      }
      ans[i] = res;
      assert(xorsum > (xorsum ^ res));
      xorsum ^= res;
    }
    puts("Yes");
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    puts("");
  }
} Tree;
int main() {
  scanf("%d", &n);
  Tree.root = Tree.newroot();
  for (int i = 0; i < n; i++) {
    long long x;
    scanf("%I64d", &x);
    Tree.Insert(x);
    Tree.xorsum ^= x;
  }
  Tree.solve();
}
