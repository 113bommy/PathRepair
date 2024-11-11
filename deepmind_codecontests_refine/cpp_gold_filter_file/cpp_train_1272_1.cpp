#include <bits/stdc++.h>
using namespace std;
long long a[100005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long q;
  int p = 1;
  for (int i = 30; i >= 0; i--) {
    q = 1 << i;
    int num = 0;
    for (int j = 1; j <= n; j++) {
      long long n = q & a[j];
      if (n == q) {
        p = j;
        num++;
      }
    }
    if (num == 1) break;
  }
  cout << a[p];
  for (int i = 1; i <= n; i++) {
    if (i != p) cout << " " << a[i];
  }
  return 0;
}
