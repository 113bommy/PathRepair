#include <bits/stdc++.h>
template <class T>
bool chmax(T &a, const T &b) {
  return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  return (b < a) ? (a = b, 1) : 0;
}
using namespace std;
const int nmax = 100010;
int a[nmax], b[nmax];
using state = tuple<int, int>;
vector<state> ary;
vector<int> ans;
int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = int(0); i < int(m); ++i) {
    int r, c;
    scanf("%d %d", &r, &c);
    r--, c--;
    a[i] = n - c, b[i] = r;
    ary.push_back(state(a[i], i));
  }
  sort(begin(ary), end(ary));
  priority_queue<state, vector<state>, greater<state>> q;
  int cur = 0;
  for (int i = int(0); i < int(n); ++i) {
    while (cur < m && get<0>(ary[cur]) <= i) {
      int idx;
      tie(ignore, idx) = ary[cur++];
      q.push(state(b[idx], idx));
    }
    while (!q.empty() && get<0>(q.top()) < i) q.pop();
    if (!q.empty()) ans.push_back(get<1>(q.top()) + 1), q.pop();
  }
  const int k = int(ans.size());
  printf("%d\n", k);
  for (int i = int(0); i < int(k); ++i) printf((i ? " %d" : "%d"), ans[i]);
  puts("");
  return 0;
}
