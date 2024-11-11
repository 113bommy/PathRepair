#include <bits/stdc++.h>
using namespace std;
ifstream fin("file.in");
ofstream fout("file.out");
int t, n, a[100005], i, s, p;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 1; i <= n; ++i) cin >> a[i];
    s = 1;
    i = n;
    p = 1;
    while (i > 1) {
      while (a[i] != s) {
        if (a[i] != a[i - 1] + 1) {
          i = -1;
          break;
        }
        i--;
        p++;
      }
      i--;
      s += p;
      p = 1;
    }
    if (i == -2)
      cout << "No";
    else
      cout << "Yes";
    cout << '\n';
  }
}
