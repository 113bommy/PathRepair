#include <bits/stdc++.h>
using namespace std;
long long ans;
struct trie {
  trie *child[2];
  long long cnt = 0;
};
trie *head;
void insert(long long x) {
  trie *cur = head;
  for (long long i = 60; i >= 0; i--) {
    long long k = (x >> i) & 1;
    if (cur->child[k] == NULL) {
      cur->child[k] = new trie();
    }
    cur = cur->child[k];
    cur->cnt++;
  }
}
void remove(long long x) {
  trie *cur = head;
  for (long long i = 60; i >= 0; i--) {
    long long k = (x >> i) & 1;
    cur = cur->child[k];
    cur->cnt--;
  }
}
void query(long long p, long long l) {
  ans = 0;
  trie *cur = head;
  for (long long i = 60; i >= 0; i--) {
    if ((1ll << i) > l) {
      long long k = (p >> i) & 1;
      if (cur->child[k] == NULL) break;
      cur = cur->child[k];
    } else {
      long long k = (p >> i) & 1;
      if ((l >> i) & 1) {
        if (cur->child[k] != NULL) ans += cur->child[k]->cnt;
        if (cur->child[!k] == NULL) break;
        cur = cur->child[!k];
      } else {
        if (cur->child[!k] == NULL) break;
        cur = cur->child[!k];
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  long long q, n, x, y;
  cin >> q;
  head = new trie();
  while (q--) {
    cin >> x;
    if (x == 1) {
      cin >> x;
      insert(x);
    } else if (x == 2) {
      cin >> x;
      remove(x);
    } else {
      cin >> x >> y;
      ans = 0;
      query(x, y);
      cout << ans << "\n";
    }
  }
}
