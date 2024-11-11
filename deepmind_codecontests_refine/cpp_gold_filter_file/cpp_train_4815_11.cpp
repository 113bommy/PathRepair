#include <bits/stdc++.h>
using namespace std;
const char newl = 10;
const string sep = "\n____\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long MOD = 1000000007;
const int MAXN = 100005;
int LOGN = 20;
vector<int> bit;
int n;
void upd(int i, int x) {
  while (i <= n) {
    bit[i] += x;
    i += i & (-i);
  }
}
int bit_search(int v) {
  int sum = 0;
  int pos = 0;
  for (int i = LOGN; i >= 0; i--) {
    if (pos + (1 << i) < n and sum + bit[pos + (1 << i)] < v) {
      sum += bit[pos + (1 << i)];
      pos += (1 << i);
    }
  }
  return pos + 1;
}
void run() {
  int q;
  cin >> n >> q;
  bit.clear();
  bit.resize(n + 1);
  vector<int> cnt(n + 1);
  for (int i = 0, tmp; i < n; i++) {
    cin >> tmp;
    upd(tmp, 1);
    cnt[tmp]++;
  }
  while (q--) {
    int k;
    cin >> k;
    if (k < 0) {
      k = -k;
      int xd = bit_search(k);
      upd(xd, -1);
      cnt[xd]--;
    } else {
      upd(k, 1);
      cnt[k]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (cnt[i]) {
      cout << i << ' ';
      return;
    }
  }
  cout << 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  for (int tc = 1; tc <= t; tc++) {
    run();
  }
  return 0;
}
