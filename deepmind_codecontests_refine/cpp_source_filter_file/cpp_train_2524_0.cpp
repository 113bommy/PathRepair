#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    long long *s = new long long[n];
    int pre[n], suf[n], len = 0;
    for (int i = 0; i < n; i++) cin >> s[i];
    pre[0] = s[0];
    for (int i = 1; i < n; i++) pre[i] = s[i] + pre[i - 1];
    suf[n - 1] = s[n - 1];
    for (int i = n - 2; i >= 0; i--) suf[i] = s[i] + suf[i + 1];
    for (int i = 0; i < n; i++)
      if (pre[i] % x != 0) len = max(len, i + 1);
    for (int i = n - 1; i >= 0; i--)
      if (suf[i] % x != 0) len = max(len, n - i);
    delete[] s;
    if (!len)
      cout << len << endl;
    else
      cout << "-1\n";
  }
}
