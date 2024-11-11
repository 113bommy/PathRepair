#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
const int inf = 0x3f3f3f3f;
char s1[maxn];
int a[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a1, b, p;
    cin >> a1 >> b >> p;
    cin >> s1 + 1;
    int len = strlen(s1 + 1);
    a[len] = 0;
    for (int i = len - 1; i >= 1; i--) {
      if (i == len - 1 || s1[i] != s1[i + 1]) {
        if (s1[i] == 'A')
          a[i] = a[i + 1] + a1;
        else
          a[i] = a[i + 1] + b;
      } else
        a[i] = a[i + 1];
    }
    for (int i = 1; i <= len; i++) {
      if (a[i] <= p) {
        cout << i << endl;
        break;
      }
    }
  }
  return 0;
}
