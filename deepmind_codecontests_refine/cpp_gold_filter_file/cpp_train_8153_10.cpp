#include <bits/stdc++.h>
using namespace std;
int cal(vector<int> a, int k) {
  int m = (int)a.size();
  if (m == 0 or m == 1) return m;
  vector<int> b(m, 0);
  for (int i = 1; i < m; i++) {
    b[i] = b[i - 1] + a[i] - a[i - 1] - 1;
  }
  int len = 0;
  for (int i = 0; i < m; i++) {
    int it = upper_bound(b.begin(), b.end(), b[i] + k) - b.begin();
    len = max(len, it - i);
  }
  return len;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> prev(n, -1), next(n, n);
  stack<int> st;
  for (int i = 0; i < n; i++) {
    while (!st.empty() and a[st.top()] > a[i]) {
      next[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }
  while (!st.empty()) st.pop();
  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() and a[st.top()] > a[i]) {
      prev[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }
  int N = 1e5 + 10;
  vector<int> A(N + 10, 0);
  vector<pair<int, int> > op;
  for (int i = 0; i < n; i++) {
    if (A[a[i]] > i) continue;
    int p1 = prev[i], p2 = next[i];
    int x = a[i];
    A[x] = next[i];
    if (p1 == -1 and p2 == n) {
    } else if (p1 == -1) {
      x -= a[p2];
    } else if (p2 == n) {
      x -= a[p1];
    } else {
      x -= max(a[p1], a[p2]);
    }
    for (int j = 0; j < x; j++) {
      op.push_back({p1 + 1, p2 - 1});
    }
  }
  cout << (int)op.size() << endl;
  for (int i = 0; i < (int)op.size(); i++)
    cout << op[i].first + 1 << " " << op[i].second + 1 << endl;
}
