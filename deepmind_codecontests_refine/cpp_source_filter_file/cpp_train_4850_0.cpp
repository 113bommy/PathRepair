#include <bits/stdc++.h>
using namespace std;
long long n, k;
vector<int> v;
string str;
void reset() {}
void input() {
  cin >> n >> k >> str;
  str.insert(0, 1, '$');
}
bool check(int value) {
  int cnt = 2, before = 1, best = INT_MAX, idx = -1;
  for (long long(i) = (2); (i) <= (n - 1); (i)++) {
    if (str[i] == '0') {
      idx = i;
    }
    if (i - before - 1 == value) {
      if (idx == -1) {
        return false;
      }
      cnt++;
      before = idx;
      idx = -1;
    }
  }
  return (cnt <= k);
}
int binser(int l, int r) {
  if (l <= r) {
    int m = (r + l) / 2;
    if (check(m)) {
      return min(m, binser(l, m - 1));
    } else {
      return binser(m + 1, r);
    }
  }
  return n - 2;
}
void solve() { cout << binser(1, n) << endl; }
void LetsRock() { solve(); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  reset();
  solve();
  return 0;
}
