#include <bits/stdc++.h>
using namespace std;
void sticks() {
  int n, count;
  cin >> n;
  count = (n - 1) % 2 + 1;
  cout << count << endl;
}
int main() {
  int i, t;
  cin >> t;
  for (i = 1; i <= t; i++) {
    sticks();
  }
  return 0;
}
