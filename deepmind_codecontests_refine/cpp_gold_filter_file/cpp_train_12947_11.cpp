#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
const long long inf = 1e12 + 10;
const double esp = 1e-7;
const int NUM = 1e5 + 10;
long long s[NUM];
long long ans[NUM];
int main() {
  int n, k;
  int i, j, x;
  while (cin >> n >> k) {
    memset(ans, 0, sizeof(ans));
    int cnt = 1;
    cin >> s[1];
    for (i = 2; i <= n; i++) {
      cin >> x;
      if (x != s[cnt]) {
        cnt++;
        s[cnt] = x;
      }
    }
    int pre = -1, last = -1;
    int mid = -1;
    ans[s[1]]++;
    ans[s[cnt]]++;
    for (i = 2; i <= cnt - 1; i++) {
      if (s[i - 1] == s[i + 1]) {
        ans[s[i]] += 2;
      } else {
        ans[s[i]]++;
      }
    }
    int maxn = 0;
    int Ans;
    for (i = k; i >= 1; i--) {
      if (ans[i] >= maxn) {
        maxn = ans[i];
        Ans = i;
      }
    }
    cout << Ans << endl;
  }
  return 0;
}
