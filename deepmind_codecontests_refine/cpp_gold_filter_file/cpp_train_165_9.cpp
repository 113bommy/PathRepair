#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e6 + 1;
const int INF = 2e9 + 2;
const long long MOD = 1e9 + 7;
const int MAXBIT = 64;
struct pos {
  int gl, gr;
  int bl, br;
};
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> input;
  for (int i = 0; i < n; ++i) {
    int val;
    cin >> val;
    input.push_back(val);
  }
  vector<pos> v(n);
  stack<pair<int, int> > st;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && st.top().first <= input[i]) {
      v[st.top().second].gr = i;
      st.pop();
    }
    st.push({input[i], i});
  }
  while (!st.empty()) {
    v[st.top().second].gr = n;
    st.pop();
  }
  for (int i = n - 1; i >= 0; --i) {
    while (!st.empty() && st.top().first < input[i]) {
      v[st.top().second].gl = i + 1;
      st.pop();
    }
    st.push({input[i], i});
  }
  while (!st.empty()) {
    v[st.top().second].gl = 0;
    st.pop();
  }
  vector<int> go(MAXBIT, -1);
  for (int i = 0; i < n; ++i) {
    int temp = input[i];
    int d = 0;
    while (temp) {
      if ((temp & 1)) go[d] = i;
      d++;
      temp >>= 1;
    }
    v[i].bl = -1;
    for (int j = 0; j < MAXBIT; ++j)
      if (go[j] != i) v[i].bl = max(v[i].bl, go[j]);
  }
  fill(go.begin(), go.end(), n + 1);
  for (int i = n - 1; i >= 0; --i) {
    int temp = input[i];
    int d = 0;
    while (temp) {
      if ((temp & 1)) go[d] = i;
      d++;
      temp >>= 1;
    }
    v[i].br = n + 1;
    for (int j = 0; j < MAXBIT; ++j)
      if (go[j] != i) v[i].br = min(v[i].br, go[j] + 1);
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (v[i].bl >= v[i].gl)
      ans += 1LL * (v[i].bl - v[i].gl + 1) * (v[i].gr - i);
    if (v[i].br <= v[i].gr)
      ans +=
          1LL * (v[i].gr - v[i].br + 1) * (i - max(v[i].bl + 1, v[i].gl) + 1);
  }
  cout << ans;
  return 0;
}
