#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, mod = 1e9 + 7;
int n;
char a[N];
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    scanf("%s", a + 1);
    int l = 1, r = n;
    while (a[l] == '<') {
      l++;
    }
    while (a[r] == '>') {
      r--;
    }
    l--;
    r++;
    if (l + r != n)
      cout << min(l, n - r + 1) << endl;
    else
      cout << min(l, n - r + 1) << endl;
  }
  return 0;
}
