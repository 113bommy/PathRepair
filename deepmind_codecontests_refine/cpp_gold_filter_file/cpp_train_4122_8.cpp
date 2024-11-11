#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &cout, vector<T> &a) {
  for (size_t i = 0; i < a.size(); ++i) cout << a[i] << " ";
  return cout;
}
template <typename T>
ostream &operator<<(ostream &cout, vector<vector<T> > &a) {
  for (size_t i = 0; i < a.size(); ++i) cout << a[i] << endl;
  return cout;
}
int main() {
  int a, b;
  char c;
  cin >> a;
  while (scanf("%c%d", &c, &b) == 2) {
    if (c == '+') {
      a += b;
    } else {
      a -= b;
    }
    a += 256;
    a %= 256;
  }
  if (a / 100) {
    for (int i = 0; i < '0' + a / 100; ++i) cout << '+';
    cout << ".>" << endl;
    a %= 100;
    for (int i = 0; i < '0' + a / 10; ++i) cout << '+';
    cout << ".>" << endl;
    a %= 10;
    for (int i = 0; i < '0' + a; ++i) cout << '+';
    cout << '.' << endl;
  } else if (a / 10) {
    for (int i = 0; i < '0' + a / 10; ++i) cout << '+';
    cout << ".>" << endl;
    a %= 10;
    for (int i = 0; i < '0' + a; ++i) cout << '+';
    cout << '.' << endl;
  } else {
    for (int i = 0; i < '0' + a; ++i) cout << '+';
    cout << '.' << endl;
  }
  return 0;
}
