#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
const int MAX_N = 2005;
const int MAX_V = 0;
const int MAX_M = 290;
const int MAX_K = 90;
int t;
string s;
char c;
int l, n;
void solve() {
  if (l >= n)
    printf("%d\n", n);
  else {
    int sum = 0, sum1 = 0;
    int b = 0, x = 0;
    while (x < n) {
      while (x < n && s[x] == c) {
        x++;
        sum1++;
      }
      if (s[x] != c && x < n) {
        l--;
        x++;
        sum1++;
      }
      while (x < n && s[x] == c) {
        x++;
        sum1++;
      }
      if (x == n) {
        sum = max(sum, sum1);
        break;
      }
      while (l == 0) {
        sum = max(sum, sum1);
        if (s[b] != c) {
          b++;
          l++;
          sum1--;
        } else if (s[b] == c) {
          b++;
          sum1--;
        }
        if (b == n) {
          printf("%d\n", sum);
          return;
        }
      }
    }
    printf("%d\n", sum);
  }
}
int main() {
  while (~scanf("%d", &n)) {
    cin >> s;
    n = s.size();
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
      scanf("%d %c", &l, &c);
      solve();
    }
  }
}
