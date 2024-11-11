#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
bool is_small(char c) { return c <= 'z' && c >= 'a'; }
char another(char c) {
  if (is_small(c)) {
    if (c == 'w') return 'b';
    return 'w';
  }
  if (c == 'W') return 'B';
  return 'W';
}
int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, char>> closest(n, {INF, 'G'});
  string s;
  cin >> s;
  for (int i = 0; i < n; ++i)
    if (s[i] != s[(i + 1) % n] && s[i] != s[(i - 1 + n) % n]) s[i] += 'a' - 'A';
  int last = -1;
  char t = 'G';
  for (int i = 0; i <= 2 * n; ++i) {
    if (is_small(s[i % n]) && last != -1) {
      if (closest[i % n].first > (i - last) % n)
        closest[i % n] = {(i - last) % n, t};
    } else if (!is_small(s[i % n]))
      last = i % n, t = s[i % n];
  }
  last = -1;
  t = 'G';
  for (int i = 2 * n; i >= 0; --i) {
    if (is_small(s[i % n]) && last != -1) {
      if (closest[i % n].first > (last - i) % n)
        closest[i % n] = {(last - i) % n, t};
    } else if (!is_small(s[i % n]))
      last = i, t = s[i % n];
  }
  for (int i = 0; i < n; ++i) {
    if (!is_small(s[i]))
      cout << s[i];
    else if (closest[i].first <= k)
      cout << closest[i].second;
    else if (k % 2)
      cout << another(s[i] + 'A' - 'a');
    else
      cout << (char)(s[i] + 'A' - 'a');
  }
  return 0;
}
