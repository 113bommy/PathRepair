#include <bits/stdc++.h>
using namespace std;
const int nmax = 100000;
int n, m;
int a[nmax + 5];
inline int abs(int x) { return x > 0 ? x : -x; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  vector<int> b(n - 1);
  for (int i = 0; i < n - 1; i++) b[i] = abs(a[i] - a[i + 1]);
  for (int k = 0; k < m; k++) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--;
    r--;
    vector<int> c(r - l);
    for (int i = l; i < r; i++) c[i - l] = b[i];
    vector<long long> L(r - l), R(r - l);
    {
      stack<pair<long long, long long> > st;
      int cur = 0;
      while (cur < r - l) {
        st.push(pair<long long, long long>(c[cur], cur));
        int i = cur + 1;
        while (i < r - l && st.top().first >= c[i]) {
          st.push(pair<long long, long long>(c[i], i));
          i++;
        }
        while (i < r - l && !st.empty() && st.top().first < c[i]) {
          pair<long long, long long> p = st.top();
          st.pop();
          L[p.second] = i - p.second;
        }
        cur = i;
      }
      while (!st.empty()) {
        pair<long long, long long> p = st.top();
        st.pop();
        L[p.second] = r - l - p.second;
      }
    }
    reverse(c.begin(), c.end());
    {
      stack<pair<long long, long long> > st;
      int cur = 0;
      while (cur < r - l) {
        st.push(pair<long long, long long>(c[cur], cur));
        int i = cur + 1;
        while (i < r - l && st.top().first > c[i]) {
          st.push(pair<long long, long long>(c[i], i));
          i++;
        }
        while (i < r - l && !st.empty() && st.top().first <= c[i]) {
          pair<long long, long long> p = st.top();
          st.pop();
          R[p.second] = i - p.second;
        }
        cur = i;
      }
      while (!st.empty()) {
        pair<long long, long long> p = st.top();
        st.pop();
        R[p.second] = r - l - p.second;
      }
    }
    reverse(c.begin(), c.end());
    reverse(R.begin(), R.end());
    long long ans = 0;
    for (int i = 0; i < r - l; i++) {
      ans += c[i] * R[i] * L[i];
    }
    printf("%d\n", ans);
  }
  return 0;
}
