#include <bits/stdc++.h>
using namespace std;
long long int positive = 100000;
long long int negative = -100000;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    long long int v1[n], v2[n], v3[n], v4[n];
    for (int i = 0; i < n; ++i) {
      v1[i] = v3[i] = negative;
      v2[i] = v4[i] = positive;
    }
    for (int i = 0; i < n; ++i) {
      int a, b, c, d, e, f;
      cin >> a >> b >> c >> d >> e >> f;
      if (c == 0) {
        v1[i] = a;
      }
      if (e == 0) {
        v2[i] = a;
      }
      if (d == 0) {
        v4[i] = b;
      }
      if (f == 0) {
        v3[i] = b;
      }
    }
    long long int minim1 = positive;
    long long int maxim1 = negative;
    long long int minim2 = positive;
    long long int maxim2 = negative;
    for (int i = 0; i < n; ++i) {
      minim1 = min(minim1, v2[i]);
      minim2 = min(minim2, v4[i]);
      maxim1 = max(maxim1, v1[i]);
      maxim2 = max(maxim2, v3[i]);
    }
    if (minim1 >= maxim1 && minim2 >= maxim2) {
      cout << 1 << " " << minim1 << " " << minim2 << endl;
    } else
      cout << 0 << endl;
  }
}
