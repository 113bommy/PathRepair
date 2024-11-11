#include <bits/stdc++.h>
using namespace std;
const double PI = 3.141592654;
string s, ss;
vector<string> vs;
vector<int> v;
int main() {
  int c = 1, x, t = 1, f = 0;
  cin >> s >> x;
  sort((s).begin(), (s).end());
  for (long long(i) = 0; (i) < (long long)(s.size() - 1); (i)++) {
    if (s[i] != s[i + 1]) c++;
  }
  int n = s.size() - c;
  if (x > s.size()) {
    cout << "impossible" << endl;
    return 0;
  }
  if (c >= x) {
    cout << "0" << endl;
    return 0;
  }
  while (c != x && n > 0) {
    n--;
    c++;
    f++;
  }
  if (c == x)
    cout << f << endl;
  else
    cout << "impossible" << endl;
  return 0;
}
