#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
const int N = 3e3 + 5;
const long long INF = 1e18;
const int mod = 998244353;
const double Pi = acos(-1);
const int p = 510200;
void Fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
struct node {
  int child[2];
  node() {
    child[0] = -1;
    child[1] = -1;
  }
};
int n;
long long sum = 0, ans = 0;
long long a[100005];
vector<node> Trie;
void Add(long long temp) {
  int node = 0;
  for (int i = 39; i >= 0; i--) {
    long long bit = (temp >> i) & 1;
    if (Trie[node].child[bit] == -1) {
      Trie[node].child[bit] = (int)Trie.size();
      Trie.emplace_back();
    }
    node = Trie[node].child[bit];
  }
}
long long Get(long long val) {
  int node = 0;
  long long ans = 0;
  for (int i = 39; i >= 0; i--) {
    long long bit = (val >> i) & 1;
    if (Trie[node].child[bit ^ 1] != -1) {
      ans ^= (1ll << bit);
      node = Trie[node].child[bit ^ 1];
    } else {
      node = Trie[node].child[bit];
    }
  }
  return ans;
}
signed main() {
  Fastio();
  Trie.resize(1);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum ^= a[i];
    ans = max(ans, sum);
  }
  long long mask = 0;
  for (int i = 1; i <= n; i++) {
    mask ^= a[i];
    ans = max(ans, sum ^ mask);
    Add(mask);
    ans = max(ans, Get(mask ^ sum));
  }
  cout << ans;
}
