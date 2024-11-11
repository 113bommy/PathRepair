#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int count = 0;
  int p1 = 0, p2 = 0;
  int coin = 0;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    p2 = p1;
    p1 = count;
    if (c == 'U') {
      count++;
    } else {
      count--;
    }
    if (i >= 2 && p1 == 0 && p2 * count < 0) {
      coin++;
    }
  }
  cout << coin << endl;
  return 0;
}
