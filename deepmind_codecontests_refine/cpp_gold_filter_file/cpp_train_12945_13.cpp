#include <bits/stdc++.h>
using namespace std;
int c = 0;
string input;
char curr, maxx;
int main() {
  string max;
  cin >> input;
  maxx = input[0];
  for (int i = 1; i < input.length(); i++) {
    curr = input[i];
    if (maxx < curr) {
      c = 0;
      maxx = curr;
    } else if (maxx == curr) {
      c++;
    }
  }
  for (int i = 0; i <= c; i++) {
    max += maxx;
  }
  cout << max << endl;
  return 0;
}
