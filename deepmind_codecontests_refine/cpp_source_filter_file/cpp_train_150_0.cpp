#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  string a;
  cin >> a;
  for (int i = 0; i < n; i++) {
    if (a[i] == '*') {
      for (int j = 1; j < n / 4; j++) {
        long long can = 0;
        for (int k = 1; k < 5; k++) {
          if (i + j * k > n - 1) break;
          if (a[i + j * k] == '*') can++;
        }
        if (can == 4) {
          cout << "yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "no" << endl;
  return 0;
}
