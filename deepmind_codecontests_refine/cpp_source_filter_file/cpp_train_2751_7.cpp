#include <bits/stdc++.h>
using namespace std;
int a, b, c, i, j;
unsigned long long int total;
priority_queue<pair<int, int> > cola;
pair<int, int> substring[50005];
string s, res;
int main() {
  cin >> s;
  c = 0;
  for (i = 0; i < s.length(); i++) {
    if (s[i] != '?') {
      c -= ((s[i] - '(') * 2 - 1);
      res += s[i];
    } else {
      cin >> a >> b;
      res += ')';
      cola.push(make_pair(b - a, i));
      c -= 1;
      total += b;
    }
    if (c < 0) {
      if (cola.empty()) {
        break;
      } else {
        res[cola.top().second] = '(';
        total -= cola.top().first;
        cola.pop();
        c += 2;
      }
    }
  }
  if (c < 0) {
    cout << "-1" << endl;
  } else {
    cout << total << endl;
    cout << res << endl;
  }
  return 0;
}
