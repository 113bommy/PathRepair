#include <bits/stdc++.h>
using namespace std;
vector<int> l1[26];
vector<int> l2[26];
int n;
long long res = 0;
long long sq = 0;
double ans;
void solve(vector<int>& a, vector<int>& b) {
  int i = 0;
  long long s = 0;
  for (auto& x : b) {
    while (a.size() > i && a[i] <= x) {
      s += a[i];
      i++;
    }
    res += s * (n - x + 1);
  }
  ans += double(res) / double(sq);
  res = 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  for (int i = 1; i <= n; i++) {
    l1[s1[i - 1] - 'A'].push_back(i);
    l2[s2[i - 1] - 'A'].push_back(i);
    if (s1[i - 1] == s2[i - 1]) {
      res -= 1LL * i * (n + 1 - i);
    }
    sq += 1LL * i * i;
  }
  ans += double(res) / double(sq);
  res = 0;
  for (int i = 0; i < 26; i++) {
    solve(l1[i], l2[i]);
    solve(l2[i], l1[i]);
  }
  printf("%.18lf", ans);
}
