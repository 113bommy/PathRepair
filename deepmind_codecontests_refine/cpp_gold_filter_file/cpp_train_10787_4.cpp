#include <bits/stdc++.h>
using namespace std;
const int N = 32;
const int M = 2e5 + 10;
vector<int> l[N + 1], r[N + 1];
int ansl[M], ansr[M];
int n;
int a[M];
int b[M];
bool bigger(int x, int y, int tp) { return tp ? x > y : x >= y; }
void work(vector<int> &l, vector<int> &r, int *a, int tp) {
  vector<int> st;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && bigger(a[i], a[st.back()], tp)) st.pop_back();
    l[i] = st.empty() ? 0 : st.back() + 1;
    st.emplace_back(i);
  }
  while (!st.empty()) st.pop_back();
  for (int i = n - 1; i >= 0; --i) {
    while (!st.empty() && a[i] >= a[st.back()]) st.pop_back();
    r[i] = st.empty() ? n - 1 : st.back() - 1;
    st.emplace_back(i);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 0; i <= N; ++i) {
    l[i].resize(n);
    r[i].resize(n);
  }
  work(l[N], r[N], a, 1);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < n; ++j) {
      b[j] = a[j] >> i & 1;
    }
    work(l[i], r[i], b, 0);
  }
  for (int i = 0; i < n; ++i) {
    ansl[i] = l[N][i], ansr[i] = r[N][i];
    for (int j = 0; j < N; ++j)
      if ((a[i] >> j & 1) == 0) {
        ansl[i] = max(ansl[i], l[j][i]);
        ansr[i] = min(ansr[i], r[j][i]);
      }
  }
  long long ans = 1ll * n * (n - 1) / 2;
  for (int i = 0; i < n; ++i) {
    ans -= 1ll * (i - ansl[i]) * (ansr[i] - i) + ansr[i] - ansl[i];
  }
  printf("%I64d\n", ans);
  return 0;
}
