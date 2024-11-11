#include <bits/stdc++.h>
using namespace std;
bool is_odd(int i) { return i % 2; }
int main() {
  int n;
  cin >> n;
  bool R = true, L = true;
  string input;
  cin >> input;
  int s = 0, t = 0;
  for (int i = 0; i < input.size(); i++) {
    if (input[i] == 'R' && R == true) {
      s = i + 1;
      R = false;
    } else if (input[i] == 'L' && L == true) {
      t = i + 1;
      L = false;
    }
    if (L == false && R == false) {
      break;
    }
    if (input[i] == '.' && R != true && L == true) {
      t = i + 1;
      break;
    } else if (input[i] == '.' && R == true && L != true) {
      t--;
      s = i;
      break;
    }
  }
  cout << s << " " << t;
  return 0;
}
