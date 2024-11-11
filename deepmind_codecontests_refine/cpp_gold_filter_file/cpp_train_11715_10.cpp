#include <bits/stdc++.h>
using namespace std;
int sum(1), tmp[26], last[26];
void add(int c) {
  sum = (sum + tmp[c]);
  while (sum >= 1000000007LL) sum -= 1000000007LL;
}
void inc(int a, int b) {
  tmp[a] += tmp[b];
  if (tmp[a] >= 1000000007LL) tmp[a] -= 1000000007LL;
}
bool comp(int a, int b) { return last[a] < last[b]; }
int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  for (int i(0); i < k; ++i) {
    tmp[i] = 1;
    last[i] = -1;
  }
  string s;
  cin >> s;
  int mx(0), now;
  for (int i(0); i < s.size(); ++i) {
    now = s[i] - 'a';
    last[now] = i;
    add(now);
    for (int j(0); j < k; ++j)
      if (j != now) {
        inc(j, now);
        if (comp(j, mx) || mx == now) mx = j;
      }
  }
  for (int i(0); i < n; ++i) {
    now = mx;
    last[now] = i + s.size();
    add(now);
    for (int j(0); j < k; ++j)
      if (j != now) {
        inc(j, now);
        if (comp(j, mx) || mx == now) mx = j;
      }
  }
  cout << sum;
}
