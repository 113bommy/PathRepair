#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main() {
  long long s = 0, n, i, x;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    s += x;
  }
  long long m = s % (n + 1);
  long long cnt = 0;
  for (i = s; i <= s + 5; i++)
    if (i % (n + 1) != 1) cnt++;
  cout << cnt << endl;
  return 0;
}
