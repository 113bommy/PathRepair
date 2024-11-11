#include <bits/stdc++.h>
using namespace std;
char st[100100];
int pos[100100], ans, last, L, R = -1;
vector<pair<int, int> > r;
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < int(s.size()); i++) {
    if (s[i] == '(' || s[i] == '[')
      st[++last] = s[i], pos[last] = i;
    else {
      char c = (s[i] == ')' ? '(' : '[');
      if (!last || c != st[last])
        last = 0;
      else
        r.push_back(make_pair(pos[last--], i));
    }
  }
  if (!r.empty()) {
    sort(r.begin(), r.end());
    int end = r[0].second, square = 0, start = r[0].first;
    for (int i = r[0].first; i <= r[0].second; i++) square += s[i] == '[';
    if (square > ans) ans = square, L = start, R = end;
    for (int i = 1; i <= int(r.size()) - 1; i++)
      if (r[i].second > last) {
        int cnt = 0;
        for (int j = r[i].first; j <= r[i].second; j++) cnt += s[j] == '[';
        if (r[i].first == end + 1)
          square += cnt;
        else
          start = r[i].first, square = cnt;
        end = r[i].second;
        if (square > ans) ans = square, L = start, R = end;
      }
    if (square > ans) ans = square, L = start, R = end;
  }
  cout << ans << endl;
  for (int i = L; i <= R; i++) cout << s[i];
  cout << endl;
}
