#include <bits/stdc++.h>
using namespace std;
vector<string> v(10000);
string x;
int q = 1;
int n;
int main() {
  cin >> n;
  cin >> x;
  for (int i = 0; i < n + 1 / 2; i = i + 2) {
    if (x.size() % 2 == 1) {
      v[(n / 2) - 1 + q] = x[i];
      int p = (n / 2) - q;
      if (p < 0) {
        break;
      }
      v[(n / 2) - q] = x[i + 1];
      q++;
    } else {
      v[(n / 2) - q] = x[i];
      q--;
      v[(n / 2) + q] = x[i + 1];
      q = q + 2;
      if (q > 6 / 2) {
        break;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << v[i];
  }
}
