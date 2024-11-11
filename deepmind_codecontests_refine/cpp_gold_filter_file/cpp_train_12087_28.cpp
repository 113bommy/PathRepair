#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k = 0, y;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> y;
    if (y == 1) k++;
  }
  if (k == 0)
    cout << "easy";
  else
    cout << "hard";
}
