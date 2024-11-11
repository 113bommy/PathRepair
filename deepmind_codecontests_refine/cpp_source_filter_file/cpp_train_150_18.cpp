#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  vector<char> v;
  cin >> n;
  v.push_back('.');
  for (int i = 0; i < n; i++) {
    char ch;
    cin >> ch;
    v.push_back(ch);
  }
  for (int i = 0; i < 100; i++) {
    char ch;
    ch = '.';
    v.push_back(ch);
  }
  for (int i = 1; i <= n; i++) {
    if (v[i] == '*') {
      a = i;
      for (int i = 1; i <= 25; i++) {
        if (v[a + i] == '*' && v[a + 2 * i] == '*' && v[a + 3 * i] == '*' &&
            v[a + 4 * i] == '*') {
          cout << "yes";
          exit(0);
        }
      }
    }
  }
  cout << "no" << a;
  return 0;
}
