#include <bits/stdc++.h>
#pragma warning(disable : 4996)
template <typename T>
T min(T x, T y) {
  return x < y ? x : y;
}
template <typename T>
T max(T x, T y) {
  return x > y ? x : y;
};
const long long MAXN = 100005;
const long long INF = 2000000000000005;
struct data {
  long long id;
  long long w;
  data(long long ID = 0, long long W = 0) {
    id = ID;
    w = W;
  }
  bool operator<(data t) const { return w < t.w; }
  bool operator==(data t) const { return id == t.id && w == t.w; }
};
struct cmp {
  bool operator()(data x, data y) { return x.w > y.w; }
};
struct heap {
  std::priority_queue<data> Q;
  std::priority_queue<data> D;
  void insert(data d) { Q.push(d); }
  void del(data d) { D.push(d); }
  data top() {
    while (D.size() && Q.top() == D.top()) D.pop(), Q.pop();
    return Q.top();
  }
};
long long N, pos[MAXN], L, S;
long long tmp[MAXN];
void solve(long long *r, long long &cost) {
  if (L < S) {
    long long p = 0;
    for (long long i = L; i >= 1; i--) r[++p] = i;
    for (long long i = L + 1; i < S; i++) r[++p] = i;
    for (long long i = S + 1; i <= N; i++) r[++p] = i;
    cost = (pos[S] - pos[1]) * 2 + pos[N] - pos[S];
    return;
  }
  long long p = 0, s = 0;
  for (long long i = S - 1; i >= 1; i--) r[++p] = i;
  std::priority_queue<data, std::vector<data>, cmp> mn;
  long long st = N - (L - (S - 1)), sum = 0;
  data end(0, INF);
  if (st == S + 1) {
    cost = 2 * (pos[N] - pos[1]) - pos[S + 1] + pos[S];
    for (long long i = N; i >= S + 1; i--) r[++p] = i;
    return;
  }
  for (long long i = S + 2; i < st; i++) mn.push(data(i, pos[i] - pos[i - 1]));
  for (long long i = st; i <= N; i++) {
    end = min(end, data(i, pos[N] - pos[i] + sum));
    mn.push(data(i, pos[i] - pos[i - 1]));
    sum += mn.top().w * 2;
    tmp[++s] = mn.top().id;
    mn.pop();
  }
  long long n = L - (S - 1) - (N - end.id);
  std::sort(tmp + 1, tmp + n + 1);
  s = 1;
  while (s < n && tmp[s] + 1 == tmp[s + 1]) s++;
  long long last = 1;
  for (long long i = S + 1; i < end.id;) {
    if (last <= n && i == tmp[last] - 1) {
      for (long long j = tmp[s]; j >= tmp[last]; j--) r[++p] = j;
      r[++p] = i;
      i = tmp[s] + 1;
      s = last = s + 1;
      while (s < n && tmp[s] + 1 == tmp[s + 1]) s++;
    } else {
      r[++p] = i;
      i++;
    }
  }
  for (long long i = N; i >= end.id; i--) r[++p] = i;
  cost = (pos[S] - pos[1]) * 2 + pos[N] - pos[S] + end.w;
}
long long out1[MAXN], cost1;
long long out2[MAXN], cost2;
int main() {
  long long i;
  scanf("%I64d %I64d %I64d", &N, &L, &S);
  for (i = 1; i <= N; i++) scanf("%I64d", pos + i);
  if (L == 0) {
    if (S != 1)
      printf("-1");
    else {
      printf("%I64d\n", pos[N] - pos[1]);
      for (long long i = 2; i <= N; i++) printf("%I64d ", i);
    }
    return 0;
  } else if (L == N - 1) {
    if (S != N)
      printf("-1");
    else {
      printf("%I64d\n", pos[N] - pos[1]);
      for (long long i = N - 1; i >= 1; i--) printf("%I64d ", i);
    }
    return 0;
  }
  solve(out1, cost1);
  std::reverse(pos + 1, pos + N + 1);
  for (long long i = 1; i <= N; i++) pos[i] = INF - pos[i];
  L = N - 1 - L;
  S = N + 1 - S;
  solve(out2, cost2);
  if (cost1 <= cost2) {
    printf("%I64d\n", cost1);
    for (int i = 1; i <= N - 1; i++) printf("%I64d ", out1[i]);
  } else {
    printf("%I64d\n", cost2);
    for (int i = 1; i <= N - 1; i++) printf("%I64d ", N + 1 - out2[i]);
  }
  return 0;
}
