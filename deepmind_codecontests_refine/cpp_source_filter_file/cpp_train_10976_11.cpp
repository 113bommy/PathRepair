#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int counter = 0;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (t * m <= 5) {
      counter++;
    }
  }
  cout << counter / 3;
  return 0;
}
