#include <bits/stdc++.h>
using namespace std;
long long int const mod = 1e9 + 7;
long long int const inf = 1e15 + 7;
long long int const mxn = 2e5 + 1;
inline void file() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    string s, s1;
    long long int n, sum = 0;
    cin >> s;
    cin >> n;
    for (long long int i = 0; i < s.size(); i++) {
      sum += (s[i] - '0');
      if (sum < n) s1 += s[i];
    }
    long long int h = 0, c = 1;
    for (long long int i = s.size() - 1; i >= 0; i--) {
      h += (s[i] - '0') * c;
      c *= 10;
    }
    c = 1;
    long long int k = 0;
    if (s1.size() != 0) {
      for (long long int i = s1.size() - 1; i >= 0; i--) {
        k += (s1[i] - '0') * c;
        c *= 10;
      }
      k++;
    } else
      k = 1;
    long long int p = (s.size() - s1.size());
    while (p--) {
      k *= 10;
    }
    if (sum <= n)
      cout << 0 << "\n";
    else
      cout << k - h << "\n";
  }
}
