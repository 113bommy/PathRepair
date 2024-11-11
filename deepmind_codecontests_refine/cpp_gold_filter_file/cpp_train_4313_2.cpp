#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 3;
const long long M = 43;
const long long SQ = 320;
const long long INF = 1e16;
const long long MOD = 1e9 + 7;
int n;
pair<int, int> a[N];
set<int> st;
double v[N][M], v1[N][M];
int c[N], c1[N];
double t[50];
int main() {
  t[0] = 1;
  for (int i = 1; i <= 42; i++) t[i] = t[i - 1] / 2;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a, a + n, greater<pair<int, int> >());
  for (int i = 0; i < n; i++) {
    st.insert(a[i].second);
    auto p1 = st.lower_bound(a[i].second);
    auto p2 = p1;
    for (int j = 0; (p1 != st.begin() && j < 40); p1--, j++) v[i][c[i]++] = *p1;
    v[i][c[i]++] = *p1;
    v[i][c[i]++] = -1;
    for (int j = 0; (p2 != st.end() && j < 40); p2++, j++) v1[i][c1[i]++] = *p2;
    v1[i][c1[i]++] = n;
  }
  double ans = 0;
  for (int i = 0; i < n; i++) {
    double r = 0;
    for (int j = 1; j < c1[i]; j++) r += t[j - 1] * (v1[i][j] - v1[i][j - 1]);
    double res = 0;
    for (int j = 1; j < c[i]; j++) res += t[j] * (v[i][j - 1] - v[i][j]) * r;
    res = res * a[i].first;
    ans += res;
  }
  cout << setprecision(10) << ans / double(n) / double(n) << endl;
  return 0;
}
