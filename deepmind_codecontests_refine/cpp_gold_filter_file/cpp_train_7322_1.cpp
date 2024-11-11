#include <bits/stdc++.h>
using namespace std;
const int N = 100020;
bool B;
int n, k, st, m;
long long a[N], T[4 * N], A[N];
long long answer, now;
int t[4 * N], C[N], P[N];
vector<pair<long long, int> > ar;
vector<int> S;
void ptf(int v) {
  if (B)
    printf("%d ", n - v + 1);
  else
    printf("%d ", v);
}
void update(int v, int tl, int tr, int l, long long x) {
  if (tl > l || tr <= l) return;
  if (tl == tr - 1) {
    t[v] = 1;
    T[v] = x;
    return;
  }
  update(v + v, tl, tl + tr >> 1, l, x);
  update(v + v + 1, tl + tr >> 1, tr, l, x);
  t[v] = t[v + v] + t[v + v + 1];
  T[v] = T[v + v] + T[v + v + 1];
}
void Build(int v, int tl, int tr) {
  if (tl == tr - 1) {
    t[v] = T[v] = 0;
    return;
  }
  Build(v + v, tl, tl + tr >> 1);
  Build(v + v + 1, tl + tr >> 1, tr);
  t[v] = T[v] = 0;
}
long long get(int v, int tl, int tr, int x) {
  if (x == 0) return 0;
  if (t[v] == x || tl == tr - 1) return T[v];
  if (t[v + v] > x) return get(v + v, tl, tl + tr >> 1, x);
  return T[v + v] + get(v + v + 1, tl + tr >> 1, tr, x - t[v + v]);
}
int main() {
  scanf("%d %d %d", &n, &k, &st);
  for (int i = 1; i <= n; ++i) scanf("%I64d", &a[i]);
  if ((k == 0 && st > 1) || (k == n - 1 && st < n)) return printf("-1\n"), 0;
  if (st - 1 > k) {
    B = true;
    for (int i = 1; i <= n; ++i) a[i] = a[n] - a[i];
    reverse(a + 1, a + n + 1);
    st = n + 1 - st;
    k = n - k - 1;
  }
  answer = a[n] + a[n] - a[st];
  if (st == k + 1) answer = min(answer, a[st] + a[n]);
  now = a[n] + a[st];
  int p = k - st + 1;
  for (int i = st + 1; i < n; ++i)
    A[i] = a[i + 1] - a[i], ar.push_back({A[i], i});
  sort(ar.begin(), ar.end());
  m = ar.size();
  for (int i = 0; i < ar.size(); ++i) C[ar[i].second] = i;
  for (int i = st + 1; i <= n; ++i) {
    if (n - i > p) {
      update(1, 0, m, C[i], A[i]);
      continue;
    }
    long long cur = now + a[n] - a[i] + 2 * get(1, 0, m, p - (n - i));
    answer = min(answer, cur);
    update(1, 0, m, C[i], A[i]);
  }
  cout << answer << endl;
  if (answer == a[n] + a[n] - a[st]) {
    int p = n - k - 1;
    for (int i = st + 1; i < st + p; ++i) ptf(i);
    if (st < n) ptf(n);
    for (int i = n - 1; i >= st + p; --i) ptf(i);
    for (int i = st - 1; i >= 1; --i) ptf(i);
    return 0;
  }
  if (k == st - 1) {
    for (int i = st - 1; i >= 1; --i) ptf(i);
    for (int i = st + 1; i <= n; ++i) ptf(i);
    return 0;
  }
  Build(1, 0, m);
  for (int i = st + 1; i <= n; ++i) {
    if (n - i > p) {
      update(1, 0, m, C[i], A[i]);
      continue;
    }
    long long cur = now + a[n] - a[i] + 2 * get(1, 0, m, p - (n - i));
    if (answer == cur) {
      for (int j = st - 1; j >= 1; --j) ptf(j);
      ar.clear();
      for (int j = st + 1; j < i; ++j) ar.push_back({A[j], j});
      sort(ar.begin(), ar.end());
      for (int j = 0; j < p - (n - i); ++j) {
        int x = ar[j].second;
        P[x + 1] = x;
      }
      for (int j = i; j < n; ++j) P[j + 1] = j;
      for (int j = st + 1; j <= n; ++j)
        if (P[j + 1] == 0) S.push_back(j);
      for (int j = 0; j < S.size(); ++j) {
        int x = S[j];
        ptf(x);
        while (P[x] != 0) {
          ptf(P[x]);
          x = P[x];
        }
      }
      return 0;
    }
    update(1, 0, m, C[i], A[i]);
  }
}
