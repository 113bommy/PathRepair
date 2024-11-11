#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long arr[N], pre[N];
struct trie {
  trie* c[2];
  trie() { c[0] = c[1] = 0; }
} * root;
void insrt(long long x) {
  trie* cur = root;
  for (int i = 40; i >= 0; i--) {
    int d = 0;
    if (x & (1ll << i)) d = 1;
    if (!cur->c[d]) cur->c[d] = new trie();
    cur = cur->c[d];
  }
}
long long gtmx(long long x) {
  trie* cur = root;
  long long ans = 0;
  for (int i = 40; i >= 0; i--) {
    int d = 0;
    if (x & (1ll << i)) d = 1;
    if (cur->c[!d]) {
      cur = cur->c[!d];
      ans += (1ll << i);
    } else if (cur->c[d]) {
      cur = cur->c[d];
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0), ios_base::sync_with_stdio(0), cin.tie(0),
      cout.tie(0);
  root = new trie();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (i)
      pre[i] = pre[i - 1] ^ arr[i];
    else
      pre[i] = arr[i];
  }
  long long suf = 0, mx = 0;
  for (int i = n - 1; i >= 0; i--) {
    insrt(suf);
    mx = max(mx, gtmx(pre[i]));
    suf ^= arr[i];
  }
  cout << max(mx, gtmx(0));
  return 0;
}
