#include <bits/stdc++.h>
using namespace std;
long long a, b, c, ans, arr[1000009], x, N = 1000009, in = 0, isComp[1000009];
void sieve() {
  isComp[0] = isComp[1] = 1;
  for (long long i = 2; i * i <= N; ++i) {
    if (!isComp[i]) {
      for (long long j = i * i; j <= N; j += i) {
        isComp[j] = 1;
      }
    }
  }
}
int main() {
  cin.sync_with_stdio(0);
  cout.sync_with_stdio(0);
  int n, k, is = 0, ans, p;
  cin >> n >> k;
  sieve();
  for (int i = 2; i < n; ++i) {
    if (!isComp[i]) {
      for (int j = i - 1; j > 0; --j) {
        if (!isComp[j]) {
          for (int h = j - 1; h > 0; --h) {
            if (!isComp[h]) {
              if (j + h + 1 == i) {
                ++is;
              }
              break;
            }
          }
        }
      }
    }
  }
  if (is >= k)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
