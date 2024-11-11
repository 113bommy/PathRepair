#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x == 0) {
      cout << "HARD";
      return 0;
    }
  }
  cout << "EASY";
  return 0;
}
