#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, easy = 0, hard = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    if (a == 1)
      hard++;
    else
      easy++;
  }
  cout << ((hard >= 1) ? "HARD" : "EASY");
}
