#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long q, b, c, n, k;
  cin >> q;
  while (q--) {
    cin >> n >> k;
    string s, s1 = "", s2 = "", s3 = "";
    cin >> s;
    for (int i = 0; i < k; i++) {
      if (i % 3 == 0) {
        s1 += 'R';
        s2 += 'G';
        s3 += 'B';
      } else if (i % 2 == 1) {
        s1 += 'G';
        s2 += 'B';
        s3 += 'R';
      } else {
        s1 += 'B';
        s2 += 'R';
        s3 += 'G';
      }
    }
    long long c1 = LONG_LONG_MAX, c2 = LONG_LONG_MAX, c3 = LONG_LONG_MAX;
    for (int i = 0; i + k - 1 < n; i++) {
      long long x1 = 0, x2 = 0, x3 = 0;
      for (int j = 0; j < k; j++) {
        if (s[i + j] != s1[j]) x1++;
        if (s[i + j] != s2[j]) x2++;
        if (s[i + j] != s3[j]) x3++;
      }
      c1 = min(c1, x1);
      c2 = min(c2, x2);
      c3 = min(c3, x3);
    }
    cout << min(c1, min(c2, c3)) << "\n";
  }
}
