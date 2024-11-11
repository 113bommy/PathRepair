#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
const long long mod = 1000000007;
int n;
int a[maxn];
int main() {
  while (cin >> n) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    int p = 0, flag = 0;
    for (int i = 2; i <= n; i++) {
      if (p == 0 && a[i] > a[i - 1]) {
      } else if (p == 0 && a[i] < a[i - 1]) {
        p = 1;
      } else if (p == 1 && a[i] < a[i - 1]) {
      } else {
        flag = 1;
      }
    }
    if (flag) {
      puts("NO");
    } else {
      puts("YES");
    }
  }
}
