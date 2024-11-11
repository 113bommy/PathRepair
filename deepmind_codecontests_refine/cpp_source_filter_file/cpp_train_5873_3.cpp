#include <bits/stdc++.h>
using namespace std;
int n, h[100005], t[100005], out[100005], x, maxx, k, m;
stack<int> st;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> h[i];
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
    out[t[i]]++;
  }
  for (int i = 1; i <= n; ++i)
    if (h[i]) {
      x = i;
      k = 0;
      while (out[x] < 2 && x) x = t[x], ++k;
      if (k > maxx) maxx = k, m = i;
    }
  cout << k << '\n';
  x = m;
  while (out[x] < 2 && x) st.push(x), x = t[x];
  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
  return 0;
}
