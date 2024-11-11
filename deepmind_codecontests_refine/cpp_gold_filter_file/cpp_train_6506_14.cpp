#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
const unsigned long long M = 1LL << 33;
const double eps = 0;
char s[N];
int main() {
  int n, m;
  cin >> n >> m;
  scanf("%s", s);
  long long res = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0 || s[i] != s[i - 1]) {
      res += n * (m - 1);
    }
  }
  int e = 0;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) continue;
    e = max(e, i + 1);
    while (e < n - 1 && s[e + 1] == s[e - 1]) e++;
    res -= max(0, e - i);
  }
  cout << res << endl;
}
