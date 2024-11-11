#include <bits/stdc++.h>
using namespace std;
int a[200];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int tmp = 1;
    for (int i = 1; i <= n / 2; i++) {
      a[i] = tmp;
      tmp += 2;
    }
    int mid = 1;
    if (n & 1)
      a[(n / 2) + 1] = tmp, mid = (n / 2) + 2;
    else
      mid = (n / 2) + 1;
    for (int i = mid; i <= n; i++) {
      tmp -= 2;
      a[i] = tmp;
    }
    for (int i = 1; i <= n; i++) {
      cout << 1 << " ";
    }
    cout << endl;
  }
}
