#include <bits/stdc++.h>
using namespace std;
const int MSIZE = 1e5;
const int INF = 1e9 + 1;
const int MOD = 1e9 + 1;
const int alpha = 256;
const double EPS = 1e-9;
int dp[2][MSIZE + 1];
int n, k;
string s;
vector<int> pos;
bool check(int mid) {
  int d = k - 1;
  int last = 0;
  while (d && last != n - 1) {
    auto it = --upper_bound(pos.begin(), pos.end(), last + mid + 1);
    if (*it == last) return false;
    d--;
    last = *it;
  }
  return last == n - 1;
}
void bin_s() {
  int l = 0, r = n;
  while (r - l > 1) {
    int mid = (r + l) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  cout << r;
}
int main() {
  cin >> n >> k;
  cin >> s;
  for (int i = 0; i < s.length(); ++i)
    if (s[i] == '0') pos.push_back(i);
  bin_s();
  return 0;
}
