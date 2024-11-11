#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
bool bc[N];
int main() {
  int n, t, g = 0;
  cin >> n;
  g = n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> t;
      if (t != -1 && t != 0) {
        if (t == 1 && !bc[i]) {
          bc[i] = 1;
          g--;
        }
        if (t == 2 && !bc[j]) {
          bc[j] = 1;
          g--;
        }
        if (t == 3 && (!bc[i] && !bc[j])) {
          if (!bc[i]) g--;
          if (!bc[j]) g--;
          bc[i] = 1;
          bc[j] = 1;
        }
      }
    }
  }
  cout << g << endl;
  for (int i = 1; i <= n; i++) {
    if (!bc[i]) cout << i << " ";
  }
}
