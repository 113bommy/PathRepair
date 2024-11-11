#include <bits/stdc++.h>
using namespace std;
const int64_t mod = (long long)1e9 + 7;
const int64_t primm = 998244353;
long long n;
char c[5005];
bool nuyn, pal;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> c;
  n = strlen(c);
  for (long long i = (long long)1; i < (long long)n / 2; i++) {
    if (c[i] != c[i - 1]) nuyn = true;
  }
  if (!nuyn || n <= 3) {
    cout << "Impossible" << endl;
    return 0;
  }
  for (long long i = (long long)1; i < (long long)n; i++) {
    nuyn = true;
    pal = true;
    for (long long j = 0; j < (long long)n + 1; j++) {
      if (c[(i + j) % n] != c[(4 * n - 1 + i - j) % n]) {
        pal = false;
        break;
      }
      if (c[(i + j) % n] != c[j]) nuyn = false;
    }
    if (pal == true && nuyn == false) {
      cout << 1 << endl;
      return 0;
    }
  }
  cout << 2 << endl;
  return 0;
}
