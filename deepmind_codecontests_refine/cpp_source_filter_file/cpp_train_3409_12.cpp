#include <bits/stdc++.h>
using namespace std;
long long a[200005];
map<int, int> mm;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mm[a[i]] = 1;
  }
  sort(a + 1, a + 1 + n);
  for (int i = 0; i <= log2(a[n] - a[1]); i++) {
    long long d = pow(2, i);
    for (int j = 1; j <= n; j++) {
      if (mm.find(a[j] + d) != mm.end() && mm.find(a[j] + 2 * d) != mm.end()) {
        cout << 3 << endl;
        cout << a[j] << " " << a[j] + d << " " << a[j] + 2 * d << endl;
        return 0;
      }
    }
  }
  for (int i = 1; i <= log2(a[n] - a[1]); i++) {
    long long d = pow(2, i);
    for (int j = 1; j <= n; j++) {
      if (mm.find(a[j] + d) != mm.end()) {
        cout << 2 << endl;
        cout << a[j] << " " << a[j] + d << endl;
        return 0;
      }
    }
  }
  cout << 1 << endl;
  cout << a[1] << endl;
  return 0;
}
