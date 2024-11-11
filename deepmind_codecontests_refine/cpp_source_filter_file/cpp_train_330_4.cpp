#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int p[n];
    for (long long int i = 0; i < n; i++) cin >> p[i];
    long long int k = n / 2;
    if (k < 5) {
      cout << "0 0 0" << endl;
      continue;
    }
    long long int g = 1, z = 1;
    for (long long int i = 1; i < k; i++) {
      if (p[i] == p[0]) {
        g++;
        z = i + 1;
      }
    }
    if (g > k / 3) {
      cout << "0 0 0" << endl;
      continue;
    }
    long long int s = 1, x = z + 1;
    for (long long int l = z + 1; l < k; l++) {
      if (p[l - 1] == p[l] || s <= g) {
        s++;
        x++;
      } else
        break;
    }
    long long int ss, co = 0;
    if (p[k] == p[k + 1]) {
      for (long long int j = k - 1; j >= x; j--)
        if (p[j] == p[k]) co++;
    }
    long long int b = k - x - co;
    if (b <= g) {
      cout << "0 0 0" << endl;
      continue;
    }
    cout << g << " " << s << " " << b << endl;
  }
  return 0;
}
