#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  bool b[n + 5][4];
  memset(b, 0, sizeof(b));
  if (k % 2 == 0) {
    for (int i = 1; i < n - 1; i++) {
      if (k) {
        b[i][1] = b[i][2] = 1;
        k -= 2;
      } else
        break;
    }
  } else {
    if (k > n - 2) {
      for (int i = 1; i < n - 1; i++) {
        b[i][1] = 1;
      }
      k -= n - 2;
      if (k > 2) {
        b[1][2] = 1;
        b[n - 2][2] = 1;
        k -= 2;
        int i = 2;
        while (k) {
          b[i][2] = 1;
          i++;
          k--;
        }
      } else if (k % 2) {
        int i = n / 2, j = n / 2;
        b[i][2] = 1;
        k--;
        while (k) {
          i++;
          j--;
          b[i][2] = 1;
          b[j][2] = 1;
          k -= 2;
        }
      } else {
        cout << "NO";
        return 0;
      }
    } else {
      if (k % 2) {
        int i = n / 2, j = n / 2;
        b[i][1] = 1;
        k--;
        while (k) {
          i--;
          j++;
          b[i][1] = 1;
          b[j][1] = 1;
          k -= 2;
        }
      } else {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES\n";
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < n; j++) {
      if (b[j][i])
        cout << '#';
      else
        cout << '.';
    }
    cout << '\n';
  }
  return 0;
}
