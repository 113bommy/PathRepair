#include <bits/stdc++.h>
using namespace std;
int a[] = {1, 2, 3, 4, 6, 12};
bool used[12];
int b[10001];
int main() {
  int n;
  cin >> n;
  string s;
  bool c;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    int d = 0;
    for (int j = 0; j < 6; j++) {
      for (int k = 0; k < 12 / a[j]; k++) {
        c = true;
        for (int l = k; l < 12; l += 12 / a[j]) {
          if (s[l] != 'X') c = false;
        }
        if (c) {
          b[++d] = a[j];
          break;
        }
      }
    }
    cout << d << " ";
    for (int j = 1; j <= d; j++) cout << b[j] << "x" << 12 / b[j] << " ";
    cout << endl;
  }
}
