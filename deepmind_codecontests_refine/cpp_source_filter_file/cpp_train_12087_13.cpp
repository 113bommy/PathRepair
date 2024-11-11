#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, easy = 0, hard = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    if (a == 1)
      easy++;
    else
      hard++;
  }
  cout << ((hard >= 1) ? "HARD" : "EASY");
}
