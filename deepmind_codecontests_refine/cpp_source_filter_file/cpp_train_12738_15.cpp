#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int res[n];
  for (int i = 0; i < n; i++) {
    res[i] = i + 1;
  }
  int i = 0;
  while (i < n) {
    swap(res[i], res[i + 1]);
    i += 2;
  }
  if (n == 1) {
    cout << -1 << endl;
  } else {
    for (int j = 0; j < n; j++) {
      cout << res[j] << " ";
    }
  }
  return 0;
}
