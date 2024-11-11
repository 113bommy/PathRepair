#include <bits/stdc++.h>
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
using namespace std;
stack<char> si;
int main() {
  ios::sync_with_stdio(false);
  string inp;
  cin >> inp;
  int len = inp.size(), ans = 0;
  for (__typeof(len) i = (0) - ((0) > (len)); i != (len) - ((0) > (len));
       i += 1 - 2 * ((0) > (len))) {
    if (inp[i] == '{' || inp[i] == '(' || inp[i] == '[' || inp[i] == '<')
      si.push(inp[i]);
    else {
      if (si.empty()) {
        cout << "Impossible";
        return 0;
      } else {
        if (!((inp[i] == '}' && si.top() == '{') ||
              (inp[i] == ')' && si.top() == '(') ||
              (inp[i] == ']' && si.top() == '[') ||
              (inp[i] == '<' && si.top() == '>')))
          ans++;
        si.pop();
      }
    }
  }
  if (!si.empty())
    cout << "Impossible";
  else
    cout << ans;
  return 0;
}
