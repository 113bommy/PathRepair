#include <bits/stdc++.h>
using namespace std;
int main() {
  string input;
  char temp;
  int n, count = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> input;
    if (i == 0) {
      count++;
      temp = input[1];
    }
    if (temp == input[0]) {
      count++;
      temp = input[1];
    }
  }
  cout << count;
}
