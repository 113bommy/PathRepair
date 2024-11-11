#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  string t = "abba";
  int a = n / 4;
  for (int i = 1; i <= a; i++) s += t;
  a = n % 4;
  for (int i = 0; i < a; i++) {
    s += t[i];
  }
  cout << s << endl;
  return 0;
}
