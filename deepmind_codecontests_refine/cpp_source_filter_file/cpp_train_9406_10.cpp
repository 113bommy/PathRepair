#include <bits/stdc++.h>
using namespace std;
void clear_stack(stack<pair<char, int> > st, vector<bool> bad) {
  while (!st.empty()) {
    bad[st.top().second] = true;
    st.pop();
  }
}
int get_sum(int l, int r, vector<int> v) {
  if (r < l) return 0;
  return (l == 0 ? v[r] : v[r] - v[l - 1]);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s;
  cin >> s;
  int n = (int)s.size();
  stack<pair<char, int> > st;
  map<char, char> closeit;
  vector<bool> bad(n + 1, false);
  closeit[')'] = '(';
  closeit[']'] = '[';
  for (int i = 0; i < n; ++i) {
    char x = s[i];
    if (!closeit.count(x)) {
      st.push({x, i});
    } else {
      char y = closeit[x];
      if (st.empty() || st.top().first != y) {
        bad[i] = true;
        clear_stack(st, bad);
      } else {
        st.pop();
      }
    }
  }
  clear_stack(st, bad);
  vector<int> v(n, 0);
  for (int i = 0; i < n; ++i) v[i] = (!i ? 0 : v[i - 1]) + (s[i] == '[');
  int mx = 0, l = -1, r = -1, lst = -1;
  bad[n] = true;
  for (int i = 0; i <= n; ++i) {
    if (bad[i]) {
      int cur = get_sum(lst + 1, i - 1, v);
      if (cur > mx) {
        mx = cur;
        l = lst + 1, r = i - 1;
      }
      lst = i;
    }
  }
  cout << mx << "\n";
  if (mx) cout << s.substr(l, r - l + 1);
  cout << "\n";
}
