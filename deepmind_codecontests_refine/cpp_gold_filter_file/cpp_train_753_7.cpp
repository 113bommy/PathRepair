#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long a, b;
    long long maxi = INT_MIN;
    cin >> a >> b;
    long long c[a];
    if (b % 2 == 1) {
      for (int j = 0; j < a; j++) {
        cin >> c[j];
        maxi = max(maxi, c[j]);
      }
      for (int j = 0; j < a; j++) {
        long long e = maxi - c[j];
        cout << e << " ";
      }
      cout << endl;
    } else {
      for (int j = 0; j < a; j++) {
        cin >> c[j];
        maxi = max(maxi, c[j]);
      }
      long long d[a];
      for (int j = 0; j < a; j++) {
        d[j] = maxi - c[j];
      }
      maxi = 0;
      for (int j = 0; j < a; j++) {
        maxi = max(maxi, d[j]);
      }
      for (int j = 0; j < a; j++) {
        long long e = maxi - d[j];
        cout << e << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
