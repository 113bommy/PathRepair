#include <bits/stdc++.h>
using namespace std;
const int inf = 100000007;
const long long linf = 1ll * inf * inf;
const int N = 500000 + 7;
const int M = 30;
const int multipleTest = 0;
multiset<long long> st;
int n;
int a[N];
long long calc() {
  long long res = 0;
  while (st.size() > 3) {
    long long tol = 0;
    for (int j = (0), _b = (3); j < _b; ++j) {
      tol += *st.begin();
      st.erase(st.begin());
    }
    res += tol;
    st.insert(tol);
  }
  while (!st.empty()) {
    res += *st.begin();
    st.erase(st.begin());
  }
  return res;
}
void solve() {
  cin >> n;
  for (int i = (0), _b = (n); i < _b; ++i) {
    int u;
    scanf("%d", &u);
    st.insert(u);
    a[i] = u;
  }
  long long res = calc();
  if (n == 1) {
    cout << 0;
    return;
  }
  st.clear();
  sort(a, a + n);
  a[1] += a[0];
  for (int i = (1), _b = (n); i < _b; ++i) st.insert(a[i]);
  res = min(res, calc() + a[1]);
  cout << res << '\n';
}
int main() {
  int Test = 1;
  if (multipleTest) {
    cin >> Test;
  }
  for (int i = 0; i < Test; ++i) {
    solve();
  }
}
