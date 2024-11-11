#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const long long inf = 1e18;
const int mod = 1e9 + 7;
int n;
int a[maxn];
struct node {
  node *ch[2];
  node *par;
  bool leaf;
  bool is;
  node() {
    is = 0;
    leaf = 0;
    par = ch[0] = ch[1] = NULL;
  }
};
struct trie {
  node *root;
  trie() { root = new node; }
  void add(int x) {
    node *v = root;
    for (int i = 30; i >= 0; i--) {
      bool bit = (x & (1 << i));
      if (v->ch[bit] == NULL) {
        v->ch[bit] = new node;
        (v->ch[bit])->par = v;
      }
      if (v->ch[1] != NULL && v->ch[0] != NULL) v->is = true;
      v = v->ch[bit];
    }
    v->leaf = true;
  }
  void del(int x) {
    node *v = root;
    for (int i = 30; i >= 0; i--) {
      bool bit = (x & (1 << i));
      v = v->ch[bit];
    }
    for (int i = 0; i <= 30; i++) {
      if (v == root) break;
      bool bit = (x & (1 << i));
      (v->par)->ch[bit] = NULL;
      if ((v->par)->is == true) break;
      v = v->par;
    }
    if (v != root) (v->par)->is = false;
  }
  int qu(int x) {
    node *v = root;
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
      bool bit = (x & (1 << i));
      bit = !bit;
      if (v->ch[bit] != NULL) {
        ans += (1 << i);
        v = v->ch[bit];
      } else {
        if (v->ch[!bit] == NULL) break;
        v = v->ch[!bit];
      }
    }
    return ans;
  }
};
map<int, int> mp;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  trie t;
  while (n--) {
    char tp;
    int x;
    cin >> tp >> x;
    if (tp == '+') {
      mp[x]++;
      if (mp[x] == 1) t.add(x);
    }
    if (tp == '-') {
      mp[x]--;
      if (mp[x] == 0) t.del(x);
    }
    if (tp == '?') cout << max(x, t.qu(x)) << "\n";
  }
}
