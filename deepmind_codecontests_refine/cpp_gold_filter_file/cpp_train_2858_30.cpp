#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  vector<string> v;
  v.push_back("January");
  v.push_back("February");
  v.push_back("March");
  v.push_back("April");
  v.push_back("May");
  v.push_back("June");
  v.push_back("July");
  v.push_back("August");
  v.push_back("September");
  v.push_back("October");
  v.push_back("November");
  v.push_back("December");
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == s) n = n + i + 1;
  }
  if (n > 12 && n % 12 == 0)
    n = 12;
  else if (n > 12 && n % 12 != 0)
    n = n % 12;
  cout << v[n - 1];
}
