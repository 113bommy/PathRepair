#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, c = 0;
  cin >> n;
  vector<string> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  if (n == 1) {
    cout << 1 << endl;
  } else {
    for (long long i = 0; i < n - 1; i++) {
      if (v[i][1] == v[i + 1][0]) {
        c++;
      }
    }
    cout << c + 1 << endl;
  }
  return 0;
}
