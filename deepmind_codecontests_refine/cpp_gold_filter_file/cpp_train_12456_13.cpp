#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  map<int, int> m;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    m[i] = x;
  }
  for (int j = 1; j <= n; j++) {
    int y = m[j];
    if (y <= n && m[y] <= n && m[m[y]] == j) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}
