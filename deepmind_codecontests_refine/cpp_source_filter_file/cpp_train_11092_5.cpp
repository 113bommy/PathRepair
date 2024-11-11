#include <bits/stdc++.h>
using namespace std;
long long mx = -1e9, mn = 1e9 + 5;
long long T, n, m, k, ans, a[200005], b, c, d, l, r, sum, mid, coin, cnt, pos,
    number, x, y, z;
vector<long long> v;
map<long long, long long> mp, mm;
map<long long, long long>::iterator it;
pair<pair<long long, long long>, string> p[1005];
queue<long long> q;
priority_queue<long long> pq;
void go() {}
int main() {
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  ans = 1e9;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == 'L' && s[i - 1] == 'R') {
      ans = min(ans, a[i] - a[i - 1]);
    }
  }
  if (ans == 1e9) {
    cout << -1;
  } else
    cout << ans / 2;
}
