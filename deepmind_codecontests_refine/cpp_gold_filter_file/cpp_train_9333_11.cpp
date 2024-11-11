#include <bits/stdc++.h>
using namespace std;
const double pi = 3.141592653589793;
const int M = 345678;
long long po[100];
long long ara[M];
long long cnt[100];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  po[0] = 0;
  for (int i = 1; i <= 33; i++) {
    po[i] = (po[i - 1] + 1) * 2 - 1;
  }
  long long n, d;
  cin >> n >> d;
  long long s = 0;
  for (int i = 33; i >= 1; i--) {
    s += (n / po[i]) * i;
    cnt[i] = n / po[i];
    n %= po[i];
  }
  if (s > 10000) {
    cout << -1 << endl;
    return 0;
  }
  cout << s << endl;
  long long cur = 1;
  for (int i = 33; i >= 1; i--) {
    for (int j = 0; j < cnt[i]; j++) {
      for (int k = 0; k < i; k++) {
        cout << cur << " ";
      }
      cur += d;
    }
  }
  return 0;
}
