#include <bits/stdc++.h>
using namespace std;
struct S {
  int a, b;
  S() {}
  S(int _a, int _b) {
    a = _a;
    b = _b;
  }
  const bool operator<(const S &o) const { return a < o.a; }
};
priority_queue<int> pq;
priority_queue<int, vector<int>, greater<int>> mpq;
map<int, int> mp;
stack<int> st;
set<int> set_i;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int cnt[100009] = {0}, cur = 0;
  for (int i = 0, tmp; i < m; i++) {
    scanf("%d", &tmp);
    if (cnt[tmp] == 0) cur++;
    cnt[tmp]++;
    if (cur == n) {
      printf("1");
      for (int j = 1; j <= n; j++) {
        cnt[j]--;
        if (cnt[j] == 0) cur--;
      }
    } else
      printf("0");
  }
  return 0;
}
