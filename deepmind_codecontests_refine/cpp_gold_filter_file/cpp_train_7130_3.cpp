#include <bits/stdc++.h>
using namespace std;
int Age(string str) {
  int output = 0;
  for (int k = 0; k < str.size(); k++) {
    output = 10 * output + (str[k] - '0');
  }
  return output;
}
int Drink(string drink) {
  if (drink == "ABSINTH" || drink == "BEER" || drink == "BRANDY" ||
      drink == "CHAMPAGNE" || drink == "GIN" || drink == "RUM" ||
      drink == "SAKE" || drink == "TEQUILA" || drink == "VODKA" ||
      drink == "WHISKEY" || drink == "WINE")
    return 1;
  else
    return 0;
}
int main() {
  int n;
  cin >> n;
  string input = {};
  long total = 0;
  for (int k = 0; k < n; k++) {
    cin >> input;
    if (input[0] >= '0' && input[0] <= '9') {
      if (Age(input) < 18) ++total;
    } else if (Drink(input))
      ++total;
  }
  cout << total;
  return 0;
}
