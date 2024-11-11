#include <bits/stdc++.h>
using namespace std;
long long t[1001];
int main() {
  long long n, i, j, m = 0, l = 0;
  cin >> n;
  for (i = 0; i < n; i++) scanf("%lld", &t[i]);
  for (i = 0; i < n; i++) {
    l = 0;
    for (j = i + 1; j <= n; j++)
      if (t[j] > t[j - 1]) break;
    l += j - i - 1;
    for (j = i - 1; j >= 0; j--)
      if (t[j] > t[j + 1]) break;
    l += i - j - 1;
    if (l >= m) m = l;
  }
  cout << m << endl;
}
