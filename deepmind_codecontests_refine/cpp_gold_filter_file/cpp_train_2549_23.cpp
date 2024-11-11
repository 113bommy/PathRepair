#include <bits/stdc++.h>
using namespace std;
int main() {
  int result;
  string s;
  cin >> s;
  int len = s.length();
  result = (len + 1) * 26 - len;
  cout << result << endl;
}
