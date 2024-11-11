#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000005;
const int maxm = 200005;
const int inf = 0x3f3f3f3f;
int n;
char s[maxn];
int a[100];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> (s + 1);
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'L') {
      for (int j = 0; j <= 9; j++) {
        if (a[j] == 0) {
          a[j] = 1;
          break;
        }
      }
    }
    if (s[i] == 'R') {
      for (int j = 9; j >= 1; j--) {
        if (a[j] == 0) {
          a[j] = 1;
          break;
        }
      }
    } else
      a[s[i] - '0'] = 0;
  }
  for (int i = 0; i <= 9; i++) cout << a[i];
}
