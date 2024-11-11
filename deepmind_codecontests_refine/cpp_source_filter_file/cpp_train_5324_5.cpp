#include <bits/stdc++.h>
using namespace std;
int si() {
  int a;
  scanf("%d", &a);
  return a;
}
long long sLL() {
  long long a;
  scanf("%lld", &a);
  return a;
}
string ss(int N) {
  char T[N];
  scanf("%s", T);
  return T;
}
const int N = 5e5 + 7;
int A[N], Cnt1[N], Cnt2[N];
int n, k, m, s;
bool Add(int a) { return ++Cnt2[a] <= Cnt1[a]; }
bool Remove(int a) { return --Cnt2[a] >= Cnt1[a]; }
void Answer(int i) {
  int cnt = m - n * k, removed = 0;
  printf("%d\n", cnt);
  for (int j = 0; j < k + cnt && i + j < m && removed < cnt; ++j)
    if (Remove(A[i + j])) printf("%d ", i + j + 1), ++removed;
}
void Read() {
  scanf("%d %d %d %d", &m, &k, &n, &s);
  for (int i = 0; i < m; ++i) scanf("%d", &A[i]);
  for (int i = 0; i < s; ++i) ++Cnt1[si()];
}
void Solve() {
  int cnt = m - n * k;
  for (int i = 0; i + k < m; i += k) {
    int col = 0;
    for (int j = 0; j < k; ++j)
      if (Add(A[i + j])) ++col;
    for (int j = 0; j < cnt && i + k + j < m; ++j)
      if (Add(A[i + k + j])) ++col;
    if (col == s) {
      Answer(i);
      return;
    }
    for (int j = 0; j < k + cnt && i + j < m; ++j) Cnt2[A[i + j]] = 0;
  }
  printf("-1");
}
int main() {
  Read();
  Solve();
  return 0;
}
