#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i = 1;
  cin >> n >> k;
  string str;
  cin >> str;
  if (n == 1 && k > 0) {
    cout << "0\n";
    return (0);
  }
  if (str[0] != '1' && k > 0) {
    str[0] = '1';
    k--;
  }
  while (k > 0 && i < n) {
    if (str[i] != '0') {
      str[i] = '0';
      k--;
    }
    i++;
  }
  cout << str << endl;
  return (0);
}
