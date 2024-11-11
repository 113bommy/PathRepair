#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int police = 0;
  int crime = 0;
  int x;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (x == -1 && police == 0)
      crime++;
    else if (x == -1 && police > 0) {
      police--;
    } else {
      police = x;
    }
  }
  cout << crime << endl;
}
