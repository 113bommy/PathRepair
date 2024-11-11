#include <bits/stdc++.h>
using namespace std;
long long mexp(long long a, long long b) {
  long long ans = 1;
  a %= 1000000007;
  while (b) {
    if (b & 1) ans = ans * a % 1000000007;
    b >>= 1;
    a = a * a % 1000000007;
  }
  return ans;
}
const int N = 100005;
bool f[N];
vector<vector<int> > d(N);
vector<set<int> > vec(N);
void add(int x) {
  if (f[x]) {
    return;
  }
  f[x] = 1;
  for (int i : d[x]) {
    vec[i].insert(x);
  }
}
int query(int k, int x, int mx) {
  if (x % k > 0 || (long long)vec[k].size() == 0 || (*vec[k].begin()) > mx) {
    return -1;
  }
  int cur = 0;
  for (long long i = 16; i >= 0; --i) {
    if ((x & (1 << i)) != 0) {
      auto it = vec[k].lower_bound(cur);
      if (it != vec[k].end()) {
        int y = *it;
        if (y <= mx && y >= (cur + (1 << i))) {
          cur += (1 << i);
        }
      }
    } else {
      auto it = vec[k].lower_bound(cur + (1 << i));
      if (it != vec[k].end()) {
        int y = *it;
        if (y <= mx && y < cur + (1 << (i + 1))) {
          cur += (1 << i);
        }
      }
    }
  }
  return cur;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      d[j].push_back(i);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int u;
      cin >> u;
      add(u);
    } else {
      int x, k, s;
      cin >> x >> k >> s;
      cout << query(k, x, s - x) << '\n';
    }
  }
  cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
  return 0;
}
