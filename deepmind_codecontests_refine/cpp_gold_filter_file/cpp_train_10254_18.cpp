#include <bits/stdc++.h>
using namespace std;
const int N = 2e3;
const int INF = INT_MAX;
string so(string s) {
  if (s.size() % 2 == 1) return s;
  string a = s, b = s;
  a.erase(s.size() / 2);
  b.erase(0, s.size() / 2);
  a = so(a);
  b = so(b);
  if (a < b)
    return string(a + b);
  else
    return string(b + a);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string a, b;
  cin >> a >> b;
  a = so(a);
  b = so(b);
  if (a == b)
    cout << "YES";
  else
    cout << "NO";
}
