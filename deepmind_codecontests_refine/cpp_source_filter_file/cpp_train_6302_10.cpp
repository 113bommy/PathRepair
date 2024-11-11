#include <bits/stdc++.h>
using namespace std;
int main() {
  string s = "";
  for (int i = 1; i <= 370; i++) s += to_string(i);
  int a;
  cin >> a;
  cout << s[a];
}
