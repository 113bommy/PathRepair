#include <bits/stdc++.h>
using namespace std;
int main() {
  int number, max1 = -1;
  int help;
  string str, name;
  cin >> number;
  for (int i = 0; i < number; i++) {
    int sum = 0;
    cin >> str;
    cin >> help;
    sum += (help * 100);
    cin >> help;
    sum -= (help * 50);
    for (int j = 0; j < 5; j++) {
      cin >> help;
      sum += help;
    }
    if (sum > max1) {
      max1 = sum;
      name = str;
    }
  }
  cout << name;
  return 0;
}
