#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[1000], t = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      t++;
    }
  }
  if (n == 1 && t == 0) {
    cout << "YES";
  } else {
    if (t == 1 && n > 1) {
      cout << "YES";
    } else {
      cout << "NO";
    }
  }
}
