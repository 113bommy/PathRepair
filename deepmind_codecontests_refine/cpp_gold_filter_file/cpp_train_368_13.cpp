#include <bits/stdc++.h>
using namespace std;
int n, w;
long long k;
int a[200111];
int b[200111];
set<pair<int, int> > st1, st2;
long long sum1, sum2;
void add(int x) {
  if (st1.size() < w) {
    sum1 += (a[x] + 1) / 2;
    st1.insert(make_pair(a[x], x));
  } else {
    if (a[x] > st1.begin()->first) {
      pair<int, int> tmp = *st1.begin();
      st1.erase(st1.begin());
      st1.insert(make_pair(a[x], x));
      st2.insert(tmp);
      sum1 += (a[x] + 1) / 2;
      sum1 -= (tmp.first + 1) / 2;
      sum2 += tmp.first;
    } else {
      sum2 += a[x];
      st2.insert(make_pair(a[x], x));
    }
  }
}
void del(int x) {
  if (st2.size() == 0) {
    sum1 -= (a[x] + 1) / 2;
    st1.erase(make_pair(a[x], x));
  } else {
    if (st1.find(make_pair(a[x], x)) != st1.end()) {
      pair<int, int> tmp = *st2.rbegin();
      st2.erase(--st2.end());
      st1.erase(make_pair(a[x], x));
      st1.insert(tmp);
      sum1 -= (a[x] + 1) / 2;
      sum2 -= tmp.first;
      sum1 += (tmp.first + 1) / 2;
    } else {
      sum2 -= a[x];
      st2.erase(make_pair(a[x], x));
    }
  }
}
int main() {
  scanf("%d%d", &n, &w);
  cin >> k;
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]), b[i] += b[i - 1];
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int it = 1;
  add(1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    while (it <= n && sum1 + sum2 <= k) {
      it++;
      if (it <= n) add(it);
    }
    ans = max(ans, b[it - 1] - b[i - 1]);
    del(i);
  }
  cout << ans << endl;
  return 0;
}
