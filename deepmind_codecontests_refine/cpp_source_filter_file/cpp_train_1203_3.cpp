#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int i = 0, max = 0;
  for (auto c : s) {
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y') {
      i++;
      if (max < i) max = i;
      i = 0;
    } else
      i++;
  }
  if (i + 1 > max) max = i - 1;
  cout << max << endl;
  return 0;
}
