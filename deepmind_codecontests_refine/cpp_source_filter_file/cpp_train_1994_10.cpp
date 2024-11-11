#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int number;
  set<int> numbers;
  for (int i = 0; i < n; i++) {
    cin >> number;
    numbers.insert(number);
  }
  set<int>::iterator it = numbers.begin(), runner = numbers.begin();
  int difference;
  if (numbers.size() == 1)
    cout << 1 << endl;
  else if (numbers.size() == 2) {
    ++runner;
    difference = *runner - *it;
    if (difference % 2 == 0)
      cout << difference / 2 << endl;
    else
      cout << difference << endl;
  } else if (numbers.size() == 3) {
    ++runner;
    difference = *runner - *it;
    ++runner;
    ++it;
    if (*runner - *it == difference)
      cout << difference << endl;
    else
      cout << -1 << endl;
  } else
    cout << -1 << endl;
  return 0;
}
