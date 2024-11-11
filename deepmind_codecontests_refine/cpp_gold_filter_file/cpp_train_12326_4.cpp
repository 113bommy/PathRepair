#include <bits/stdc++.h>
using namespace std;
long long a[103];
long long b[103];
int main() {
  long long N;
  cin >> N;
  for (long long i = 1; i <= N; ++i) cin >> a[i];
  long long mx = 0x8000000000000000;
  long long tb, te, tmp;
  for (long long i = 1; i <= N; ++i)
    for (long long j = i + 1; j <= N; ++j)
      if (a[i] == a[j]) {
        tmp = 0;
        tmp += a[i];
        tmp += a[j];
        for (long long k = i + 1; k < j; ++k)
          if (a[k] > 0) tmp += a[k];
        if (tmp > mx) {
          mx = tmp;
          tb = i;
          te = j;
        }
      }
  long long cnt = 0;
  for (long long i = tb + 1; i < te; ++i) {
    if (a[i] < 0) b[cnt++] = i;
  }
  cout << mx << ' ' << cnt + tb - 1 + N - te << endl;
  for (long long i = 1; i < tb; ++i) cout << i << ' ';
  for (long long i = 0; i < cnt; ++i) cout << b[i] << ' ';
  for (long long i = te + 1; i <= N; ++i) cout << i << ' ';
  cout << endl;
  return 0;
}
