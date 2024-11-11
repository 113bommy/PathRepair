#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  long long int a[n], b[100000] = {0}, m = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 2; j <= sqrt(a[i]); j++) {
      if (a[i] % j == 0) {
        if (j * j == a[i]) {
          b[j]++;
        } else {
          b[j]++;
          b[a[i] / j]++;
        }
      }
    }
    b[a[i]]++;
  }
  for (int i = 2; i < 400; i++) {
    if (b[i] > m) m = b[i];
  }
  cout << m;
}
