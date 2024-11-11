#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k;
  cin >> n >> k;
  string str;
  cin >> str;
  if (n == 1 && k >= 1) {
    cout << 0;
    return 0;
  }
  if (str[0] != '1' && k > 1) {
    str[0] = '1';
    k--;
  }
  int i = 1;
  while (k > 0 && i < n) {
    if (str[i] - '0' > 0) {
      str[i] = '0';
      k--;
    }
    i++;
  }
  cout << str;
  return 0;
}
