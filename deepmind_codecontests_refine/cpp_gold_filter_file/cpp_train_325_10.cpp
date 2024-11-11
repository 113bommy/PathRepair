#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, i;
  cin >> n >> y >> x;
  string s;
  cin >> s;
  int k = y;
  int count = 0;
  for (i = n - 1; k > 0; i--) {
    if (s[i] == '1' && n - i != x + 1) count++;
    if (s[i] == '0' && n - i == x + 1) count++;
    k--;
  }
  if (s[i] == 0) count++;
  cout << count << endl;
}
