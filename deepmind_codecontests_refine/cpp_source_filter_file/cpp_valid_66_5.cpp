#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[1000];
  int d = 1;
  int t;
  cin >> t;
  for (int i = 1; i < 1666; i++) {
    if (i % 3 == 0 || i % 10 == 3) {
      continue;
    }
    a[d] = i;
    d++;
  }
  while (t--) {
    int n;
    cin >> n;
    cout << a[n] << endl;
  }
}
