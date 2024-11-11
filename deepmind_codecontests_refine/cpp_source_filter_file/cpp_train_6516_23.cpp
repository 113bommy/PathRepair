#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  string t = "abc";
  int a = n / 3;
  for (int i = 1; i <= a; i++) s += t;
  a = n % 3;
  for (int i = 0; i < a; i++) {
    s += t[i];
  }
  cout << s << endl;
  return 0;
}
