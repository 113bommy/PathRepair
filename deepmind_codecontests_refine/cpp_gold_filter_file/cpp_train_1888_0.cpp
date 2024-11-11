#include <bits/stdc++.h>
using namespace std;
multiset<int> s[33];
long long sum[33];
long long beg[33];
int Q;
int cur, d;
char c;
int tot;
int find_set(int n) {
  int j = 1;
  for (int i = 0; i < 31; i++) {
    if (j >= n) {
      return i;
    }
    j = j << 1;
  }
}
int solve() {
  int cnt = tot;
  long long ct = 0;
  for (int i = 0; i < 31; i++) {
    if (beg[i] > 2 * ct) {
      --cnt;
    }
    ct += sum[i];
  }
  return cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    cin >> c;
    if (c == '+') {
      ++tot;
      cin >> d;
      cur = find_set(d);
      sum[cur] += d;
      s[cur].insert(d);
      if (s[cur].empty())
        beg[cur] = 0;
      else
        beg[cur] = *s[cur].begin();
    } else {
      --tot;
      cin >> d;
      cur = find_set(d);
      sum[cur] -= d;
      s[cur].erase(s[cur].find(d));
      if (s[cur].empty())
        beg[cur] = 0;
      else
        beg[cur] = *s[cur].begin();
    }
    cout << solve() << endl;
  }
}
