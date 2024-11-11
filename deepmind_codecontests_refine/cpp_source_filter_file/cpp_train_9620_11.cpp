#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-12;
const int INF = (1 << 31) - 1;
const long long LLINF = ((long long)1 << 62) - 1;
const int maxn = 1000 * 100 + 10;
long long n, j, k, m, answer, l, r, d[maxn];
string s;
int main() {
  getline(cin, s);
  n = (int)s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'M') {
      k++;
    } else {
      j++;
    }
  }
  if (k == 0 || j == 0) {
    cout << 0;
    return 0;
  }
  j = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'F') {
      k = 0;
      if (j == 0) {
        d[j] = i;
      } else {
        if (m != 0) {
          d[j] = max(d[j - 1] + 1, m);
        } else {
          d[j] = 0;
        }
      }
      j++;
    } else {
      k++;
      m++;
    }
  }
  answer = d[j - 1];
  cout << answer;
}
