#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char a[] = {'R', 'O', 'Y'};
  char b[] = {'B', 'I', 'V'};
  string s = "ROYG";
  int l = 0, r = 0;
  for (int i = 1; i <= n - 4; i++) {
    if (i % 4 == 0) {
      s += 'G';
      r = 0;
    } else {
      s += b[r++];
    }
  }
  cout << s << endl;
  return 0;
}
