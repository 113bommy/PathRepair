#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ara[100001], pos = 0;
  cin >> n;
  string str;
  cin >> str;
  for (int i = 0; i < n; i++) {
    cin >> ara[i];
  }
  for (int i = 1; i <= 1000000; i++) {
    if (str[pos] == '>') {
      pos += ara[pos];
    } else if (str[pos] == '<') {
      pos -= ara[pos];
    }
    if (pos < 0 || pos >= str.size()) {
      cout << "FINITE" << endl;
      return 0;
    }
  }
  cout << "INFINITE" << endl;
  return 0;
}
