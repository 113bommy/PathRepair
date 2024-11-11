#include <bits/stdc++.h>
using namespace std;
int c[100002];
int main() {
  string a, b;
  cin >> a >> b;
  double q = (sqrt(5.0) + 1.0) / 2.0;
  int n = max(a.length(), b.length()) + 1;
  for (int i = 0; i < a.length(); i++) {
    if (a[i] == '1') c[a.length() - i - 1]++;
  }
  for (int i = 0; i < b.length(); i++) {
    if (b[i] == '1') c[b.length() - i - 1]--;
  }
  for (int i = n; i > 1; i--) {
    if (c[i] != 0) {
      if (c[i] > 0 && c[i - 1] >= 0 && c[i - 2] >= 0) {
        cout << ">";
        return 0;
      }
      if (c[i] < 0 && c[i - 1] <= 0 && c[i - 2] <= 0) {
        cout << "<";
        return 0;
      }
      if (c[i] > 0) {
        c[i - 1] += c[i];
        c[i - 2] += c[i];
        c[i] = 0;
      }
      if (c[i] < 0) {
        c[i - 1] += c[i];
        c[i - 2] += c[i];
        c[i] = 0;
      }
    }
  }
  if (c[1] == 0 && c[0] == 0) {
    cout << "=";
    return 0;
  }
  double w = 0;
  w += c[1] * q + c[0];
  if (w < 0) {
    cout << "<";
  } else {
    cout << ">";
  }
}
