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
  if (x == 0 && sum == 0) {
    cout << "Bicarp";
    return 0;
  } else if (x * sum < 0 && 2 * abs(sum) == 9 * abs(x)) {
    cout << "Bicarp";
    return 0;
  }
  cout << "Monocarp";
  return 0;
}
