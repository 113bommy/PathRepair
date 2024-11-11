#include <bits/stdc++.h>
const double Pi = acos(-1.0);
using namespace std;
const int maxN = 200005;
int N;
long long a[maxN];
long long s1[maxN], s2[maxN];
vector<pair<long long, long long> > lines;
long long get(pair<long long, long long> l, long long x) {
  return l.first * x + l.second;
}
long long query(long long x) {
  int l = 0, r = lines.size() - 1, m;
  while (l < r) {
    m = (l + r) >> 1;
    if (get(lines[m], x) >= get(lines[m + 1], x))
      r = m;
    else
      l = m + 1;
  }
  return get(lines[l], x);
}
bool check(pair<long long, long long> l1, pair<long long, long long> l2,
           pair<long long, long long> l3) {
  return 1.0 * (l3.second - l1.second) / (l1.first - l3.first) <=
         1.0 * (l2.second - l1.second) / (l1.first - l2.first);
}
void add(pair<long long, long long> l) {
  while (lines.size() > 1 && check(lines[lines.size() - 2], lines.back(), l))
    lines.pop_back();
  lines.push_back(l);
}
int main(int argc, char** argv) {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%lld", &a[i]);
    s1[i] = s1[i - 1] + a[i];
    s2[i] = s2[i - 1] + a[i] * i;
  }
  long long ans = s2[N];
  add(pair<long long, long long>(1, 0));
  for (int i = 2; i <= N; i++) {
    ans = max(ans, query(a[i]) + s1[i - 1] + s2[N] - a[i] * i);
    add(pair<long long, long long>(i, -s1[i - 1]));
  }
  lines.clear();
  add(pair<long long, long long>(N, -s1[N]));
  for (int i = N - 1; i; i--) {
    ans = max(ans, query(a[i]) + s1[i] + s2[N] - a[i] * i);
    add(pair<long long, long long>(i, -s1[i]));
  }
  printf("%lld\n", ans);
  return 0;
}
