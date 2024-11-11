#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int MAXBITS = 50;
long long num[N];
struct Node {
  int key;
  Node *child[2];
  Node() {
    child[0] = child[1] = NULL;
    key = 0;
  }
};
Node *root = new Node;
struct Trie {
  void insert(long long val) {
    Node *s = root;
    for (int i = MAXBITS; i >= 0; i--) {
      int dir = ((1LL << i) & val) > 0;
      if (s->child[dir] == NULL) {
        Node *p = new Node;
        p->key = dir;
        s->child[dir] = p;
      }
      s = s->child[dir];
    }
  }
  long long query(long long val) {
    long long res = 0;
    Node *s = root;
    for (int i = MAXBITS; i >= 0; i--) {
      int dir = ((1LL << i) & val) > 0;
      if (s->child[!dir] != NULL) {
        s = s->child[!dir];
      } else {
        s = s->child[dir];
      }
      res += (1LL << i) * s->key;
    }
    return res;
  }
} s;
int main() {
  int n, i;
  cin >> n;
  long long prefix = 0, suffix = 0, ans = 0;
  for (i = 1; i <= n; i++) {
    scanf("%I64d", &num[i]);
    suffix ^= num[i];
  }
  for (i = 1; i <= n + 1; i++) {
    s.insert(prefix);
    long long x = s.query(suffix);
    ans = max(ans, (x ^ suffix));
    prefix ^= num[i], suffix ^= num[i];
  }
  cout << ans << endl;
  return 0;
}
