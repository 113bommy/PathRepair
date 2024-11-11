#include <bits/stdc++.h>
using namespace std;
const int maxN = 2000;
const int inf = -1;
int a[maxN];
bool check(int n) {
  for (int i = 0; i < n; i++) {
    if (a[i] == inf) {
      return false;
    }
  }
  return true;
}
int main() {
  int n, m, c;
  cin >> n >> m >> c;
  memset(a, inf, sizeof a);
  do {
    int b;
    cin >> b;
    if (b < c / 2) {
      for (int i = 0; i < n; i++) {
        if (a[i] == inf || a[i] > b) {
          a[i] = b;
          cout << i + 1 << endl;
          break;
        }
      }
    } else {
      for (int i = n - 1; i >= 0; i--) {
        if (a[i] == inf || a[i] < b) {
          a[i] = b;
          cout << i + 1 << endl;
          break;
        }
      }
    }
  } while (!check(n) || !is_sorted(a, a + n));
  return 0;
}
