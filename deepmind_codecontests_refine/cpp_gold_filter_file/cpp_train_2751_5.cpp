#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  long long ans = 0, b = 0;
  priority_queue<pair<int, int>> Q;
  for (size_t i = 0; i != str.length(); ++i) {
    if (str[i] == '(')
      ++b;
    else if (str[i] == ')')
      --b;
    else {
      --b;
      str[i] = ')';
      int x, y;
      cin >> x >> y;
      ans += y;
      Q.push(make_pair(y - x, i));
    }
    if (b < 0) {
      if (Q.empty()) break;
      pair<int, int> tmp = Q.top();
      Q.pop();
      ans -= tmp.first;
      str[tmp.second] = '(';
      b += 2;
    }
  }
  if (b)
    cout << -1 << endl;
  else
    cout << ans << endl << str << endl;
}
