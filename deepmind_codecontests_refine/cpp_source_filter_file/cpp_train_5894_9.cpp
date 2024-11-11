#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[400005];
long long trie[6000001][2];
long long ptr = 2;
void insert(long long num) {
  long long cur = 1;
  for (long long i = 20; i >= 0; i--) {
    if (!trie[cur][(num >> i) & 1]) trie[cur][(num >> i) & 1] = ptr++;
    cur = trie[cur][(num >> i) & 1];
  }
}
long long min_xor(long long num) {
  long long cur = 1;
  long long ans = 0;
  for (long long i = 20; i >= 0; i--) {
    long long bit = (num >> i) & 1;
    if (trie[cur][bit])
      cur = trie[cur][bit];
    else {
      cur = trie[cur][bit ^ 1];
      ans |= (1 << i);
    }
  }
  return ans;
}
void solve() {
  cin >> n >> m;
  set<long long> second;
  for (long long i = 0; i < n; i++) {
    long long num;
    cin >> num;
    second.insert(num);
  }
  n = 0;
  for (long long i = 0; i <= 400001; i++) {
    if (!second.count(i)) insert(i);
  }
  long long last = 0;
  while (m--) {
    long long x;
    cin >> x;
    cout << min_xor(x ^ last) << "\n";
    last ^= x;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}
