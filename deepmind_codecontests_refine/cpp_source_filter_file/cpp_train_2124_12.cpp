#include <bits/stdc++.h>
using namespace std;
int const MAXN = 2e5 + 10;
int n, m, T;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  if (n != 1) return puts("-1"), 0;
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        int up = i - 1;
        int down = n - i;
        int left = j - 1;
        int right = n - j;
        int d = min({up, down, left, right}) + (k & 1);
        if (d & 1)
          cout << "w";
        else
          cout << "b";
      }
      cout << endl;
    }
    if (k != n) cout << endl;
  }
  return 0;
}
