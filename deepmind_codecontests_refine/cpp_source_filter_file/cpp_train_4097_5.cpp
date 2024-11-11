#include <bits/stdc++.h>
using namespace std;
string input;
int main() {
  cin >> input;
  int last = 0;
  for (char i = 'z'; i >= 'a'; i--)
    for (int j = last + 1; j < input.length(); j++)
      if (input[j] == i) {
        cout << input[j];
        last = j;
      }
  return 0;
}
