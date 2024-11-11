#include <bits/stdc++.h>
using namespace std;
struct state {
  int a, b, idx;
  state() {}
  state(int a, int b, int idx) : a(a), b(b), idx(idx) {}
  bool operator<(const state &e) const {
    if (e.b != b) return b < e.b;
    return e.a < a;
  }
};
const int N = 1e5;
int n, p, k;
state st[N];
long long cum[N];
priority_queue<int> qu;
vector<int> sol;
vector<pair<int, int> > v;
int main(int argc, char **argv) {
  scanf("%d%d%d", &n, &p, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &st[i].a, &st[i].b);
    st[i].idx = i;
  }
  sort(st, st + n);
  for (int i = 0; i < n; ++i) cum[i] = (i ? cum[i - 1] : 0) + st[i].b;
  long long sum = 0;
  int rem = p - k, at;
  pair<long long, long long> best(-1, -1);
  for (int i = n - 1; i >= rem; --i) {
    if (qu.size() < k) {
      sum += st[i].a;
      qu.push(-st[i].a);
    } else if (st[i].a > -qu.top()) {
      sum -= -qu.top();
      qu.pop();
      sum += st[i].a;
      qu.push(-st[i].a);
    }
    if (qu.size() != k) continue;
    long long d = 0;
    if (i != rem) d = cum[i - 1] - (i > 1 ? cum[i - 2] : 0);
    if (sum > best.first || (sum == best.first && d >= best.second)) {
      at = i;
      best = make_pair(sum, d);
    }
  }
  for (int i = at - 1; i >= 0 && rem != 0; --i, --rem) sol.push_back(st[i].idx);
  for (int i = at; i < n; ++i) v.push_back(make_pair(st[i].a, st[i].idx));
  sort(v.begin(), v.end());
  while ((int)sol.size() != p) {
    sol.push_back(v.back().second);
    v.pop_back();
  }
  for (int i = 0; i < p; ++i) printf("%s%d", i ? " " : "", sol[i] + 1);
  puts("");
  return 0;
}
