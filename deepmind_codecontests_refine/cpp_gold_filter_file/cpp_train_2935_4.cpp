#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e15;
const int MAXM = 1e2 + 3;
const int MAXN = 3e3 + 1;
int main() {
  int n;
  cin >> n;
  int p = 0;
  for (int i = 1; i <= n; i++) {
    p = 1 - p;
    int q = p;
    for (int j = 1; j <= n; j++) {
      if (j == n) {
        if (q == 1) {
          cout << "W";
        } else {
          cout << "B";
        }
        continue;
      }
      if (q == 1) {
        cout << "W";
      } else {
        cout << "B";
      }
      q = 1 - q;
    }
    cout << "\n";
  }
  return 0;
}
