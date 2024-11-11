#include <bits/stdc++.h>
long long inf = 1LL << 62;
long long mod = 1000000007;
using namespace std;
typedef struct {
  long long b[2];
} node;
node N;
vector<node> trie;
long long a[100010];
void inject(long long x) {
  long long cur = 0;
  for (long long i = 45; i >= 0; i--) {
    long long bit = (x >> i) & 1;
    if (trie[cur].b[bit] == -1) {
      trie[cur].b[bit] = trie.size();
      trie.push_back(N);
    }
    cur = trie[cur].b[bit];
  }
}
long long query(long long x) {
  long long res = 0;
  long long cur = 0;
  for (long long i = 45; i >= 0; i--) {
    long long bit = (x >> i) & 1;
    bit = 1 - bit;
    if (trie[cur].b[bit] != -1) {
      res |= (1 << i);
      cur = trie[cur].b[bit];
    } else {
      cur = trie[cur].b[1 - bit];
    }
  }
  return res;
}
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> a[i];
  N.b[0] = -1;
  N.b[1] = -1;
  trie.push_back(N);
  inject(0);
  long long x = 0, ans = 0;
  for (long long i = 0; i < n; i++) {
    x ^= a[i];
    ans = max(ans, x);
    inject(x);
  }
  x = 0;
  for (long long i = n - 1; i >= 0; i--) {
    x ^= a[i];
    ans = max(ans, query(x));
  }
  cout << ans;
  return 0;
}
