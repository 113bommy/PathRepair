#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int cost;
  double amount;
  cin >> cost;
  string s[n];
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int counter = 1;
  double sum = 1.0;
  for (int i = n - 2; i >= 0; i--) {
    if (s[i] == "halfplus") {
      counter++;
      sum = (sum + 0.5) * 2;
    } else if (s[i] == "half") {
      sum = sum * 2;
    }
  }
  double num;
  num = sum - (0.5 * counter);
  amount = cost * num;
  cout << (long int)amount << endl;
}
