#include <bits/stdc++.h>
using namespace std;
typedef struct node {
  long long int jump, start, till;
} node;
long long int a[200010];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, m, s, d;
  cin >> n >> m >> s >> d;
  long long int i, j, r, k;
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  stack<node> st, st2;
  long long int start = 0;
  pair<long long int, long long int> p;
  node t1, t2;
  if (d == 1) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    bool flag = 1;
    start = 0, k = a[0] - 1;
    if (k < 0)
      flag = 0;
    else {
      for (i = 0; i < n;) {
        r = (k - start);
        j = ((a[i] + 1) - k);
        if (r >= s && j <= d) {
          t1.start = start;
          t1.jump = k;
          t1.till = a[i] + 1;
          st.push(t1);
          start = a[i] + 1;
          i++;
          if (i < n) k = a[i] - 1;
        } else {
          if (st.empty()) {
            flag = 0;
            break;
          } else {
            t2 = st.top();
            st.pop();
            start = t2.start;
            k = t2.jump;
          }
        }
      }
    }
    while (!st.empty()) {
      st2.push(st.top());
      st.pop();
    }
    if (flag) {
      while (!st2.empty()) {
        t1 = st2.top();
        st2.pop();
        cout << "RUN " << (t1.jump - t1.start) << '\n';
        cout << "JUMP " << (t1.till - t1.jump) << '\n';
      }
      if (t1.till != m) {
        cout << "RUN " << (m - t1.till) << '\n';
      }
    } else
      cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
