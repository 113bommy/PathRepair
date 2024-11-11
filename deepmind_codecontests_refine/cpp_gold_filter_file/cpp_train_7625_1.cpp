#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string st;
    cin >> st;
    long long n = st.size();
    char a[n];
    long long r = 0;
    long long p = 0;
    long long s = 0;
    for (long long i = 0; i < n; i++) {
      if (st[i] == 'R') {
        a[i] = 'P';
        p++;
      } else if (st[i] == 'S') {
        a[i] = 'R';
        r++;
      } else {
        a[i] = 'S';
        s++;
      }
    }
    long long ma;
    ma = max(r, max(p, s));
    if (ma == r) {
      for (long long i = 0; i < n; i++) cout << 'R';
    } else if (ma == p) {
      for (long long i = 0; i < n; i++) cout << 'P';
    } else {
      for (long long i = 0; i < n; i++) cout << 'S';
    }
    cout << endl;
  }
  return 0;
}
