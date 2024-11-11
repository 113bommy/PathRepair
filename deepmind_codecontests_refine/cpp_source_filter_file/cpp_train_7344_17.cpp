#include <bits/stdc++.h>
using namespace std;
long long int n, b, d;
long long int a[1000007];
long long int res = 0;
int main() {
  cin >> n >> b >> d;
  long long int tmp = 0;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    if (a[i] < b) {
      tmp += a[i];
      if (tmp >= d) {
        tmp -= d;
        res++;
      }
    }
  }
  cout << res;
  return 0;
}
