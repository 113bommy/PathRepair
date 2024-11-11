#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5;
int n;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if ((i % 3 != 0) && (j % 3 != 0) && (n - i - j > 0) &&
          ((n - i - j) % 3 != 0)) {
        cout << i << " " << j << " " << (n - i - j) << endl;
        return 0;
      }
  return 0;
}
