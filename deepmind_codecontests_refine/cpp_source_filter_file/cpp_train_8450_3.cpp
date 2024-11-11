#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  long long int x = 0, sum = 0;
  for (int i = 0; i < n / 2; i++) {
    if (s[i] == '?')
      x++;
    else
      sum += s[i] - '0';
  }
  for (int i = n / 2; i < n; i++) {
    if (s[i] == '?')
      x--;
    else
      sum -= s[i] - '0';
  }
  if (2 * sum == 9 * x) {
    cout << "Bicarp";
    return 0;
  }
  cout << "Monocarp";
  return 0;
}
