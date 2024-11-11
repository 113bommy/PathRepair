#include <bits/stdc++.h>
using namespace std;
const int N = 56;
int T;
long long a[N];
int main() {
  cin >> T;
  a[0] = 1;
  for (int i = 1; i <= 51; i++) {
    a[i] = a[i - 1] * 2;
  }
  while (T--) {
    string s;
    cin >> s;
    int n = s.size();
    int m = 100;
    for (int i = 0; i <= 40; i++) {
      long long j = a[i];
      string ss;
      while (j) {
        ss += ((j % 10) + '0');
        j /= 10;
      }
      reverse(ss.begin(), ss.end());
      int cnt = 0, u = 0, q = ss.size();
      for (int k = 0; k < n; k++) {
        if (s[k] == ss[u]) cnt++, u++;
      }
      m = min(m, n - cnt + q - cnt);
    }
    cout << m << endl;
  }
}
