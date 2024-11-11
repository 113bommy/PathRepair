#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0, i = 0, e = 0, t = 0;
  string input;
  cin >> input;
  for (int b = 0; b < input.length(); b++) {
    if (input[b] == 'n') {
      n++;
    } else if (input[b] == 'i') {
      i++;
    } else if (input[b] == 'e') {
      e++;
    } else if (input[b] == 't') {
      t++;
    }
  }
  while (t > i || t > (n - 1) / (3 - 1) || t > e / 3) {
    t--;
  }
  cout << t;
}
