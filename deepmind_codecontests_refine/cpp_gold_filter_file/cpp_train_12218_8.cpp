#include <bits/stdc++.h>
using namespace std;
template <class T>
T pmax(T a, T b) {
  return max(a, b);
}
const long long int mod = 1e9 + 7;
const long long int Maa = 1e2 + 1;
long long int n, q, c[Maa][Maa], m;
string s[Maa];
int main() {
  long long int k, j;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      if (s[i - 1][j - 1] == '0') {
        c[i][j] += 1;
      }
      c[i][j] += c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];
    }
  }
  long long int ans = 0;
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      for (int k = i; k < n + 1; k++) {
        for (int l = j; l < m + 1; l++) {
          if ((c[k][l] - c[k][j - 1] - c[i - 1][l] + c[i - 1][j - 1]) ==
              (k - i + 1) * (l - j + 1)) {
            ans = pmax(ans, ((k - i + 1) + (l - j + 1)) * 2LL);
          }
        }
      }
    }
  }
  cout << ans;
}
