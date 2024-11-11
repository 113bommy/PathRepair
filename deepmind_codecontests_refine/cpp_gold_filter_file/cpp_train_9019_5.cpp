#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, x, y;
  cin >> n;
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    m[x]++;
    m[y]++;
  }
  for (int i = 1; i < 6; i++) {
    if (m[i] != 2) {
      cout << "WIN";
      return 0;
    }
  }
  cout << "FAIL";
}
