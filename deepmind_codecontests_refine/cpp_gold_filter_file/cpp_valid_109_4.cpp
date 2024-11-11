#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 0;
  int n = 0;
  cin >> t;
  string s = "";
  int sum1 = 0;
  int number_of_non_zeros = 0;
  for (int i = 0; i < t; i++) {
    cin >> n;
    cin >> s;
    sum1 = 0;
    number_of_non_zeros = 0;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] != '0') {
        int e = s[j] - '0';
        number_of_non_zeros++;
        sum1 += e;
      }
    }
    if (s[s.size() - 1] != '0') {
      number_of_non_zeros--;
    }
    cout << (sum1 + number_of_non_zeros) << endl;
  }
}
