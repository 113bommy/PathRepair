#include <bits/stdc++.h>
using namespace std;
long long int cal(string b) {
  long long int i, x = 0;
  for (i = (0); i < (b.size()); ++i) {
    x = x * 10 + (b[i] - '0');
  }
  return x;
}
long long int f(long long int x) {
  stringstream is;
  is << x;
  string s;
  s = is.str();
  string b("");
  long long int i;
  for (i = (0); i < (s.size()); ++i) {
    int x;
    x = s[i] - '0';
    x = 9 - x;
    stringstream is;
    is << x;
    b = b + is.str();
  }
  return cal(b);
}
int main() {
  long long int i, a, b, l;
  cin >> a >> b;
  l = max(a * f(a), b * f(b));
  for (i = 5;; i = i * 10) {
    if (i > b) {
      break;
    }
    if (i < a) {
      continue;
    }
    l = max(l, i * f(i));
  }
  cout << l << endl;
  return 0;
}
