#include <bits/stdc++.h>
using namespace std;
int main() {
  long long q;
  cin >> q;
  while (q--) {
    long long n, count = 0;
    cin >> n;
    long long a[100005];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    if (n == 1)
      cout << "1" << endl;
    else {
      for (int i = 0; i < n; i++) {
        if (a[i] - a[i + 1] == -1) count++;
      }
      if (count > 0)
        cout << "2" << endl;
      else
        cout << "1" << endl;
    }
  }
}
