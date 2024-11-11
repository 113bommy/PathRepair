#include <bits/stdc++.h>
using namespace std;
string s;
long long l, f;
int main() {
  cin >> s;
  long long o = s.find('^');
  for (int i = 0; i < o; i++) {
    if (s[i] != '=') f += (s[i] - '0') * (o - i);
  }
  for (int i = o + 1; i < s.size(); i++) {
    if (s[i] != '=') l += (s[i] - '0') * (i - o);
  }
  if (l == f)
    cout << "balance";
  else if (f > l)
    cout << "left";
  else
    cout << "right";
  return 0;
}
