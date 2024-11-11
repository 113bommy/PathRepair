#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long int var;
  cin >> var;
  while (var--) {
    long long int i, j, k, l, m, n;
    cin >> n >> m;
    if (n > m)
      cout << "1" << endl;
    else {
      j = m / (n - 1);
      k = m % (n - 1);
      if (k == 0) {
        l = j * n;
        l--;
        cout << l << endl;
      } else {
        l = j * n;
        cout << l + k << endl;
      }
    }
  }
}
