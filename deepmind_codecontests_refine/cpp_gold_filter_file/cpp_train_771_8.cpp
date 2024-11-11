#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const long long INF = (long long)(1 << 30) * (1 << 30);
long long a[N];
long long cnt, n, i, j;
int main() {
  cin >> n;
  for (int k = 1; k <= n; k++) cin >> a[k];
  for (int head = 1; head <= n;) {
    cnt++;
    for (i = head; i <= n && a[i] == -1; i++)
      ;
    for (j = i + 1; j <= n && a[j] == -1; j++)
      ;
    if ((a[j] - a[i]) % (j - i)) {
      head = j;
      continue;
    }
    long long d = (a[j] - a[i]) / (j - i);
    if (a[i] - d * (i - head) <= 0) {
      head = j;
      continue;
    }
    for (head = j + 1; head <= n && a[j] + (head - j) * d > 0 &&
                       (a[head] == -1 || a[head] == a[j] + (head - j) * d);
         head++)
      ;
  }
  cout << cnt;
  return 0;
}
