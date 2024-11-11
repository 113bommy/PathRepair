#include <bits/stdc++.h>
using namespace std;
bool check(int x) {
  if (x == 1) return true;
  for (int i = 2; i <= sqrt(x); i++)
    if (x % i == 0) return false;
  return true;
}
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n;
    cin >> n;
    if (check(n)) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
          cout << "1"
               << " ";
        cout << endl;
      }
    } else {
      int N = n;
      while (!check(N) || !check(N - n + 1)) N++;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (j == i)
            cout << N - n + 1 << " ";
          else
            cout << "1"
                 << " ";
        }
        cout << endl;
      }
    }
  }
  return 0;
}
