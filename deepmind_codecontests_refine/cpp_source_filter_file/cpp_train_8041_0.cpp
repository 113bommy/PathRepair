#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    int e = 0, o = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] % 2)
        o++;
      else
        e++;
    }
    if (n % 2 and e + 1 != o or (n % 2 == 0 and e != o)) {
      cout << -1 << endl;
      continue;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
      if (i % 2 != a[i] % 2) count++;
    cout << count / 2 << endl;
  }
}
