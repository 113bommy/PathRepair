#include <bits/stdc++.h>
using namespace std;
long long a[105];
int main() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (long long i = 1; i <= 2 * n; i++) {
    for (long long j = 1; j < n;) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
        cout << j << " " << j + 1 << endl;
        j += 2;
      } else {
        j++;
      }
    }
  }
}
