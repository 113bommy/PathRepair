#include <bits/stdc++.h>
using namespace std;
long long n, k, a[10001], b[10001], guy, t;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> t;
    for (int j = 1; j <= t; j++) {
      cin >> b[j];
    }
    sort(b + 1, b + t + 1);
    if (b[1] < k) {
      guy++;
      a[i] = i;
    }
  }
  cout << guy << endl;
  for (int i = 1; i <= guy; i++) {
    cout << a[i] << ' ';
  }
}
