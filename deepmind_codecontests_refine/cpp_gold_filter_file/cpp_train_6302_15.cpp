#include <bits/stdc++.h>
using namespace std;
int a[100];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  string s = "", ds;
  int n, k, di;
  for (int i = 0; i < 1000; ++i) {
    di = i;
    ds = "";
    while (di > 0) {
      ds += (di % 10 + 48);
      di /= 10;
    }
    reverse(ds.begin(), ds.end());
    s += ds;
  }
  cin >> n;
  cout << s[n - 1];
  return 0;
}
