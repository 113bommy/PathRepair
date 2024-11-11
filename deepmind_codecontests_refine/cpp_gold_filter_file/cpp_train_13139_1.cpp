#include <bits/stdc++.h>
using namespace std;
const long long N = 100100 * 2;
long long n, q, f;
bool a[3][N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> q;
  while (q--) {
    long long i, j;
    cin >> i >> j;
    a[i][j] = !a[i][j];
    if (a[i][j]) {
      if (a[3 - i][j - 1]) f++;
      if (a[3 - i][j]) f++;
      if (a[3 - i][j + 1]) f++;
    } else {
      if (a[3 - i][j - 1]) f--;
      if (a[3 - i][j]) f--;
      if (a[3 - i][j + 1]) f--;
    }
    if (!f)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}
