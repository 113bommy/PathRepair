#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long add(long long x, long long y, long long CMOD = MOD) {
  return (x + y + CMOD + CMOD) % CMOD;
}
long long mult(long long x, long long y, long long CMOD = MOD) {
  return add(x, 0) * add(y, 0) % CMOD;
}
long long fast_expo(long long x, long long y, long long CMOD = MOD) {
  if (x == 0) return 0;
  if (y == 0) return 1;
  long long ans = fast_expo(x, y / 2, CMOD);
  ans = mult(ans, ans, CMOD);
  if (y & 1) ans = mult(ans, x, CMOD);
  return ans;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long gen(long long x, long long y) {
  if (x == y) return x;
  return x + rng() % (y - x + 1);
}
const int TAM = 2e5 + 100;
const long long INF = LLONG_MAX / 4;
vector<int> pos[26];
vector<int> f(string s, string r) {
  for (int i = 0; i < 26; i++) {
    pos[i].clear();
    pos[i].push_back(0);
  }
  for (int i = 0; i < r.size(); i++) pos[r[i] - 'a'].push_back(i + 1);
  int m = r.size();
  int n = s.size();
  vector<int> ans(n);
  int ma = 0;
  for (int i = 0; i < n; i++) {
    int ind = s[i] - 'a';
    int l = 0, h = pos[ind].size() - 1, mid;
    while (h - l > 1) {
      mid = l + (h - l) / 2;
      if (pos[ind][mid] <= ma + 1)
        l = mid;
      else
        h = mid;
    }
    if (pos[ind][h] <= ma + 1)
      ans[i] = pos[ind][h];
    else
      ans[i] = pos[ind][l];
    ma = max(ma, ans[i]);
  }
  return ans;
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  string s, r;
  cin >> s >> r;
  vector<int> left = f(s, r);
  reverse((s).begin(), (s).end());
  reverse((r).begin(), (r).end());
  vector<int> right = f(s, r);
  reverse((right).begin(), (right).end());
  bool ok = true;
  int n = r.size();
  for (int i = 0; i < s.size(); i++) ok &= (left[i] + right[i] >= n);
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
