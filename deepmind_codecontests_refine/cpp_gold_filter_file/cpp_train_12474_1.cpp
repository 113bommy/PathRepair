#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int a;
  cin >> s >> a;
  for (int i = 0; i < s.size(); i += a) {
    cout << s[i];
  }
  cout << endl;
}