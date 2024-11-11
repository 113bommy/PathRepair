#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
const long long N = 5e2 + 1;
const long long mod = 1e9 + 7;
const long double eps = 1E-7;
int solve(int a1) {
  int cnt = 0;
  for (int i = 0; i < a1; i++) {
    string s1;
    int n1, m1;
    cin >> s1 >> n1 >> m1;
    if (n1 >= 2400 and m1 > n1) cnt++;
  }
  return cnt;
}
int n, m, a[N], mx, cnt;
map<long long, long long> mp, pm;
vector<int> v, t;
int main() {
  int a, b;
  cin >> a >> b;
  int d = 1;
  mp[1] = 0;
  for (int i = 0; i < abs(a - b); i++) {
    if (mp[d] == 2) d++;
    mp[d]++, cnt += d;
  }
  cout << cnt;
}
