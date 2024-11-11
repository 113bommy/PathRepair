#include <bits/stdc++.h>
using namespace std;
int n;
int changed;
int answer1, answer2 = 1023;
int main() {
  cin >> n;
  int i;
  for (i = 0; i < n; i++) {
    char tp;
    cin >> tp;
    if (tp == '|') {
      int number;
      cin >> number;
      answer1 |= number;
      answer2 |= number;
      changed |= number;
    } else if (tp == '&') {
      int number;
      cin >> number;
      answer1 &= number;
      answer2 &= number;
      number = 1023 - number;
      changed |= number;
    } else {
      int number;
      cin >> number;
      answer1 ^= number;
      answer2 ^= number;
    }
  }
  int answer11 = 0;
  int answer22 = 0;
  int answer33 = 0;
  for (i = 0; i < 10; i++) {
    if ((answer1 & (1 << i)) && (answer2 & (1 << i))) {
      answer11 += 1 << i;
    } else {
      if ((answer1 & (1 << i)) && (!(answer2 & (1 << i)))) {
        answer33 += 1 << i;
        answer22 += 1 << i;
      }
      if ((!(answer1 & (1 << i))) && (answer2 & (1 << i))) {
        answer22 += 1 << i;
      }
    }
  }
  cout << 3 << endl;
  cout << "& " << answer22 << endl;
  cout << "| " << answer11 << endl;
  cout << "^ " << answer33 << endl;
  return 0;
}
