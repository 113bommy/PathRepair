#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int bit[MAXN];
int p[MAXN];
void add(int i, int x) {
  while (i < MAXN) {
    bit[i] += x;
    i += -i & i;
  }
}
int sum(int i) {
  int sum = 0;
  while (i) {
    sum += bit[i];
    i -= -i & i;
  }
  return sum;
}
set<int> s[MAXN];
set<int>::iterator it1, it2;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]), s[p[i]].insert(i), add(i, 1);
  long long ans = 0, up, last = 0;
  up = *max_element(p + 1, p + n + 1);
  for (int i = 1; i <= up; i++) {
    if (s[i].empty()) continue;
    it2 = it1 = lower_bound(s[i].begin(), s[i].end(), last);
    if (it2 != s[i].begin()) {
      ans += sum(n) - sum(last);
    } else
      ans += sum(*s[i].rbegin()) - sum(last);
    while (it1 != s[i].end()) {
      add(*it1, -1);
      last = *it1;
      it1++;
    }
    if (it2 != s[i].begin()) {
      for (it1 = s[i].begin(); it1 != it2; it1++) {
        ans++;
        add(*it1, -1);
        last = *it1;
      }
      ans += sum(last);
    }
  }
  cout << ans << endl;
}
