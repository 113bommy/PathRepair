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
  int counter = 0;
  double sum = 0.0;
  for (int i = n - 1; i >= 0; i--) {
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
  cout << (long long int)amount << endl;
}
