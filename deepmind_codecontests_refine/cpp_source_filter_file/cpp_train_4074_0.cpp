#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
int t, n, m, j, ans, k, a, b, c, d, e, f, sum, i, r, sz;
string s, s2, s3, s4;
vector<int> v;
int ar[(int)(1e6 + 10)], ar2[(int)(1e6 + 10)];
void brainfuck();
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  brainfuck();
  return 0;
}
void brainfuck() {
  int temp[10];
  cin >> t;
  while (t--) {
    cin >> k;
    c = 0;
    for (i = 1; i <= 7; i++) cin >> temp[i];
    for (i = 1, j = 7; i <= 7; i++, j--)
      ar[i] = ar[i - 1] + temp[i], ar2[j] = ar2[j + 1] + temp[j], c += temp[i];
    ans = INT_MAX;
    for (i = 1; i <= 7; i++) {
      for (j = 1; j <= 7; j++) {
        a = ar2[i] + ar[j];
        e = 7 - i + 1;
        e += j;
        b = k - a;
        if (b >= 0 && b % c == 0) {
          f = b / c;
          f = f * 7;
          ans = min(ans, f + e);
        }
        if (j >= i) {
          e = abs(ar2[i] - ar[j]);
          if (e == k) ans = min(ans, j - i + 1);
        }
      }
    }
    cout << ans << "\n";
  }
}
