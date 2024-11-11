#include <bits/stdc++.h>
const long long INF = (long long)1e18 + 123;
const int inf = (int)2e9 + 123;
const int mod = 1e9 + 7;
using namespace std;
string s = "", t = "", a, b;
int main() {
  unsigned int FOR;
  asm("rdtsc" : "=A"(FOR));
  srand(FOR);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> a >> b;
  n = a.length();
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  reverse(b.begin(), b.end());
  int l1 = 0, r1 = n / 2 + n % 2 - 1, l2 = 0, r2 = n / 2 - 1;
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 1) {
      if (a[l1] < b[r2]) {
        s += a[l1];
        l1++;
      } else {
        t += a[r1];
        r1--;
      }
    } else {
      if (b[l2] > a[r1]) {
        s += b[l2];
        l2++;
      } else {
        t += b[r2];
        r2--;
      }
    }
  }
  reverse(t.begin(), t.end());
  cout << s + t;
  return 0;
}
