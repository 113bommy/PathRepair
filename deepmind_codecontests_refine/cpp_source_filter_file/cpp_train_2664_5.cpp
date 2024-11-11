#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  char c[] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V'};
  string s = "";
  cin >> n;
  int n1 = 0, n2 = n1 + 1, n3 = n2 + 1, n4 = n3 + 1;
  for (int i = 0; i < n; i++) {
    if (i == n - 4) {
      s += "BIV";
      break;
    }
    if (i == n1) {
      s += 'R';
      n1 += 4;
    } else if (i == n2) {
      s += 'O';
      n2 += 4;
    } else if (i == n3) {
      s += 'Y';
      n3 += 4;
    } else if (i == n4) {
      s += 'G';
      n4 += 4;
    }
  }
  cout << s;
}
