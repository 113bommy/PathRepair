#include <bits/stdc++.h>
using namespace std;
long long int a[500002], b[500002], c[500002];
char st[500002];
int main() {
  long long int maxm = 0, At = 0, n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cin >> st;
  for (int i = 1; i <= n; i++) {
    if (st[i - 1] == 'B') {
      b[i] = a[i] + b[i - 1];
    } else
      b[i] = b[i - 1];
  }
  for (int i = n; i >= 1; i--) {
    if (st[i - 1] == 'A') {
      At = At + a[i];
      maxm = max(maxm, At + b[i]);
    } else
      maxm = max(maxm, At + b[i]);
  }
  for (int i = n; i >= 1; i--) {
    if (st[i - 1] == 'B') {
      c[i] = a[i] + c[i - 1];
    } else
      c[i] = c[i - 1];
  }
  At = 0;
  for (int i = 1; i <= n; i++) {
    if (st[i - 1] == 'A') {
      At = At + a[i];
      maxm = max(maxm, At + c[i]);
    } else
      maxm = max(maxm, At + c[i]);
  }
  cout << maxm;
}
