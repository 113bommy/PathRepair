#include <bits/stdc++.h>
using namespace std;
long double eps = 0.0000000001;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string second;
  int sum = 0, n;
  cin >> n;
  cin >> second;
  int y = 0;
  for (int i = 0; i < n; i++) {
    if (second[i] = '0') {
      y = 1;
    }
  }
  if (y = 1) {
    cout << "YES" << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    sum += int(second[i]) - 48;
  }
  int sum2 = 0;
  for (int i = 0; i < n; i++) {
    sum2 += int(second[i]) - 48;
    sum -= int(second[i]) - 48;
    if (sum2 != 0 && sum % sum2 == 0 && sum != 0) {
      int first = 1;
      int x = 0;
      for (int j = i + 1; j < n; j++) {
        x += int(second[j]) - 48;
        if (x > sum2) {
          first = 0;
          break;
        } else if (x == sum2) {
          x = 0;
        }
      }
      if (x != 0) {
        first = 0;
      }
      if (first == 1) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
