#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long int h[n];
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  long long int b[n];
  long long int max = 0;
  for (int j = 0; j < n; j++) {
    if (j == 0) {
      max = h[n - j - 1];
      b[n - j - 1] = max - 1;
    } else {
      if (max > h[n - j - 1]) {
        b[n - j - 1] = max;
      } else if (max < h[n - j - 1]) {
        max = h[n - j - 1];
        b[n - j - 1] = max - 1;
      } else if (max == h[n - j - 1]) {
        b[n - j - 1] = max;
      }
    }
  }
  for (int k = 0; k < n; k++) {
    if (h[k] == b[k]) {
      cout << "0" << endl;
    } else if (b[k] > h[k]) {
      cout << (b[k] - h[k] + 1) << endl;
    } else if ((h[k] - b[k]) > 0) {
      cout << "0";
    }
  }
}
