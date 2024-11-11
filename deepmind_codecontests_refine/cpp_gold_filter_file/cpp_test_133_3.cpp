#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a[n - 2];
    string s;
    long long int i, k, j, f = 0;
    for (i = 0; i < n - 2; i++) {
      cin >> a[i];
    }
    if (n == 3) {
      s = "b" + a[0];
    } else {
      s = s + a[0];
      for (i = 1; i < n - 2; i++) {
        if (a[i][0] != a[i - 1][1]) {
          s = s + a[i][0];
          f = 1;
        }
        s = s + a[i][1];
      }
      if (f == 0) s = s + "a";
    }
    cout << s << endl;
  }
}
