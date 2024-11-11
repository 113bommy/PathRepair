#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, c = 0, d = 0, sum = 0, e = 0;
  cin >> n;
  int a[n];
  vector<int> b;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 2; i < n - 1; i++) {
    if (a[i] == 0) {
      if (a[i - 1] == 1 && a[i + 1] == 1) {
        c++;
        b.push_back(i);
        sum++;
      }
    }
  }
  if (b.size() == 0) {
    cout << 0;
  } else {
    for (i = 0; i < b.size() - 1; i++) {
      d = b[i + 1] - b[i];
      if (d == 2) {
        e++;
        i = i + 1;
      }
    }
    cout << b.size() - e;
  }
}
