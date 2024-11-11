#include <bits/stdc++.h>
using namespace std;
int sign = 1, sum = 0, temp = 0, cur = 0;
int main() {
  string s;
  cin >> s;
  for (auto i : s)
    if (i == '+' || i == '-') {
      sum += sign * temp;
      temp = 0;
      sign = i == '+' ? 1 : -1;
    } else
      temp = temp * 10 + i - '0';
  sum += sign * temp;
  vector<int> v;
  if (!sum) v.push_back('0');
  while (sum) {
    v.push_back(sum % 10 + '0');
    sum /= 10;
  }
  reverse(v.begin(), v.end());
  for (auto i : v) {
    while (i--) cout << "+";
    cout << "." << endl;
    cout << ">" << endl;
  }
}
