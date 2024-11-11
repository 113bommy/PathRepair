#include <bits/stdc++.h>
using namespace std;
int n;
long long C, m;
long long answer;
long long T[21][200020];
pair<long long, long long> a[100020];
void Build() {
  n++;
  for (int i = 1; i <= n + 1; ++i) T[0][i] = a[i].second;
  for (int k = 1; (1 << k) <= n; ++k)
    for (int i = 1; i + (1 << (k - 1)) <= n; ++i)
      T[k][i] = min(T[k - 1][i], T[k - 1][i + (1 << (k - 1))]);
}
int Get(int ind) {
  int cur = a[ind].second;
  for (int k = 20; k >= 0; --k) {
    if (ind + (1 << k) > n + 1) continue;
    if (T[k][ind] >= cur) ind += (1 << k);
  }
  return ind;
}
int main() {
  scanf("%I64d%I64d%d", &m, &C, &n);
  for (int i = 1; i <= n; ++i) scanf("%I64d%I64d", &a[i].first, &a[i].second);
  a[n + 1] = make_pair(m, 0LL);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n + 1; ++i)
    if (a[i].first - a[i - 1].first > C) return cout << "-1", 0;
  Build();
  long long cur = C;
  for (int i = 1; i <= n; ++i) {
    cur -= a[i].first - a[i - 1].first;
    int k = Get(i);
    long long p = cur;
    cur = min(C, max(cur, a[k].first - a[i].first));
    answer += (cur - p) * 1LL * a[i].second;
  }
  cout << answer << endl;
  return 0;
}
