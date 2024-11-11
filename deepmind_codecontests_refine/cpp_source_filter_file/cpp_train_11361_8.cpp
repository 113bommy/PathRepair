#include <bits/stdc++.h>
using namespace std;
const char s[30] = "abcdefghijklmnopqrtsuvwxyz";
int main() {
  int n;
  cin >> n;
  while (n--) {
    int x, y;
    cin >> x >> y;
    int t = x / y;
    for (int i = 0; i < t; i++)
      for (int j = 0; j < y; j++) cout << s[j];
    int k = x % y;
    for (int i = 0; i < k; i++) cout << s[i];
    cout << endl;
  }
  return 0;
}
