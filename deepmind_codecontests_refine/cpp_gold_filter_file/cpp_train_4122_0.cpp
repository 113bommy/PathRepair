#include <bits/stdc++.h>
using namespace std;
int main() {
  int ans;
  cin >> ans;
  char c;
  while (cin >> c) {
    if (c != '+' && c != '-') break;
    int i;
    cin >> i;
    if (c == '+')
      ans += i;
    else
      ans -= i;
  }
  if (ans == 0) {
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++.\n";
    return 0;
  }
  vector<int> vec;
  while (ans) {
    vec.push_back(ans % 10);
    ans /= 10;
  }
  for (int i = vec.size() - 1; i >= 0; --i) {
    for (int j = 0; j < vec[i]; ++j) cout << '+';
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++.>\n";
  }
  return 0;
}
