#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char t[n];
  int i;
  int h = n;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  i = 0;
  while (i < n) {
    if ((t[i] == 'U' && t[i + 1] == 'R') || (t[i] == 'R' && t[i + 1] == 'U')) {
      i += 2;
      h--;
    } else
      i++;
  }
  cout << h;
  return 0;
}
