#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 5;
long long int a[N], b[N], c[N];
int main() {
  long long int n;
  while (cin >> n) {
    memset(b, 0, sizeof(b));
    for (long long int i = 1; i <= n; i++) {
      cin >> a[i];
      b[a[i]]++;
    }
    long long int maxx = 0, sum = 0, j = 0;
    for (long long int i = 0; i <= 200000; i++) {
      if (b[i] > maxx) {
        maxx = b[i];
        sum = i;
      }
    }
    for (long long int i = 1; i <= n; i++) {
      if (a[i] == sum) {
        j = i;
        break;
      }
    }
    cout << n - maxx << endl;
    for (long long int i = j - 1; i >= 1; i--) {
      if (a[i] == sum) continue;
      if (a[i] > sum)
        cout << "1 " << i << " " << i + 1 << endl;
      else
        cout << "2 " << i << " " << i + 1 << endl;
    }
    for (long long int i = j + 1; i <= n; i++) {
      if (a[i] == sum) continue;
      if (a[i] < sum)
        cout << "1 " << i << " " << i - 1 << endl;
      else
        cout << "2 " << i << " " << i - 1 << endl;
    }
  }
  return 0;
}
