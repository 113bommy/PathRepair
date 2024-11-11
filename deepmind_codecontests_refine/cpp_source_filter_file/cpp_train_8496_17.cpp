#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int MAXN = 1e2 + 5;
const long long MOD = 1e9 + 7;
int a[1005][3000];
int main() {
  int n, s, d;
  int maxx = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s >> d;
    for (int j = s; j <= 11; j += d) {
      if (j > maxx) {
        maxx = j;
        break;
      }
    }
  }
  cout << maxx << endl;
  return 0;
}
