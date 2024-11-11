#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, n;
  cin >> s >> n;
  int x[n], y[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if ((x[i] > x[j])) {
        int temp = x[i];
        x[i] = x[j];
        x[j] = temp;
        int temp2 = y[i];
        y[i] = y[j];
        y[j] = temp2;
      }
    }
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (s >= x[i]) {
      s += y[i];
      count++;
    }
  }
  if (count == n) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
