#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main() {
  int n;
  cin >> n;
  ;
  cout << n / 2 * (n + 1) / 2 << endl;
  ;
  for (int i = 0; i < n; i += 2) {
    for (int j = 1; j < n; j += 2) {
      cout << (i + 1) << " " << (j + 1) << endl;
    }
  }
}
