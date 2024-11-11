#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
bool compare(pair<long long int, pair<long long int, long long int> > &a,
             pair<long long int, pair<long long int, long long int> > &b) {
  if (a.first == b.first) {
    return a.second.second <= b.second.second;
  }
  return a.first < b.first;
}
bool isPrime(long long int n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}
long long int solve() {
  long long int n, k, m;
  cin >> n >> k;
  string s, t = "", r;
  long long int count = 0, prev = 0, cnt = 0, ans = 0, curr = 0;
  bool turn = 1, win = 0, flag = 1;
  vector<long long int> v(n, 0);
  for (int i = 0; i < n; i++) cin >> v[i];
  if (v[0] != 0) {
    ans = 1;
  } else if (n == 1) {
    ans = k + 1;
  } else {
    count = k;
    for (int i = 1; i < n; i++) {
      cnt = (long long int)pow((long long int)10, v[i]) -
            (long long int)pow((long long int)10, v[i - 1]);
      if (count * (long long int)pow((long long int)10, v[i - 1]) < cnt) {
        ans += (count + 1) * (long long int)pow((long long int)10, v[i - 1]);
        count = -1;
        break;
      } else {
        ans += cnt;
        count -= cnt / (long long int)pow((long long int)10, v[i - 1]);
      }
    }
    ans += (count + 1) * (long long int)pow((long long int)10, v[n - 1]);
  }
  cout << ans << endl;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test = 1;
  cin >> test;
  for (int i = 0; i < test; i++) {
    solve();
  }
}
