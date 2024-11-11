#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
long long a[N], b[N];
deque<long long> qa, qb;
int l = 0, r = -1;
void left() {
  if (!qa.empty() && qa.front() == l) qa.pop_front();
  if (!qb.empty() && qb.front() == l) qb.pop_front();
  l++;
  r = max(r, l - 1);
}
void right() {
  r++;
  while (!qa.empty() && a[r] > a[qa.back()]) qa.pop_back();
  while (!qb.empty() && b[r] < b[qb.back()]) qb.pop_back();
  qa.push_back(r);
  qb.push_back(r);
}
int maxApos() {
  assert(!qa.empty());
  return qa.front();
}
int minBpos() {
  assert(!qb.empty());
  return qb.front();
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = (0); i < (n); i++) cin >> a[i];
  for (int i = (0); i < (n); i++) cin >> b[i];
  long long ans = 0;
  while (l < n) {
    while (r < n - 1 && ((l <= r && max(a[maxApos()], a[r + 1]) <=
                                        min(b[minBpos()], b[r + 1])) ||
                         (r < l && a[r + 1] <= b[r + 1]))) {
      right();
    }
    if (l <= r && a[maxApos()] == b[minBpos()]) {
      ans += r - max(maxApos(), minBpos()) + 1;
    }
    left();
  }
  cout << ans << '\n';
}
