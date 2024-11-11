#include <bits/stdc++.h>
using namespace std;
int ara[] = {2, 6, 2, 3, 3, 4, 2, 5, 1, 2};
int main() {
  string s;
  cin >> s;
  int n = s[0] - '0';
  int sum = ara[n];
  n = s[1] - '0';
  sum *= ara[n];
  cout << sum;
}
