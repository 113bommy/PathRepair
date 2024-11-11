#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string a;
    cin >> a;
    int j = strlen(&a[0]);
    if (j > 10) {
      cout << a[0] << j - 2 << a[j - 1] << endl;
    } else {
      cout << a << endl;
    }
  }
  return 0;
}
