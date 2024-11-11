#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  stack<pair<int, char> > q;
  for (int i = 0; i < s.size(); ++i) {
    char c = s[i];
    if (!q.empty()) {
      if (c == '0' && q.top().second == '1') {
        q.pop();
        continue;
      }
    }
    q.push({i, c});
  }
  while (!q.empty()) {
    int idx, c;
    tie(idx, c) = q.top();
    if (c == '1') {
      s[idx] = '0';
    }
    q.pop();
  }
  cout << s << endl;
  return 0;
}
