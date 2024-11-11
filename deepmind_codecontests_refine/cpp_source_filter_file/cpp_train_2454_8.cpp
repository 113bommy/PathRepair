#include <bits/stdc++.h>
using namespace std;
int main() {
  int lemon, apple, pears;
  int count = 0;
  cin >> lemon >> apple >> pears;
  for (int i = 1; i <= lemon, 2 * i <= apple, 4 * i <= pears; i++) {
    count++;
  }
  cout << count * 7;
  return 0;
}
