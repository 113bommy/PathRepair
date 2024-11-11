#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int m[n];
  for (int i = 0; i < n; i++) {
    cin >> m[i];
    if (m[i] == 1) {
      cout << "HARD";
      return 0;
    }
  }
  cout << "EASY";
}
