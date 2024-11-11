#include <bits/stdc++.h>
using namespace std;
void sieve(int* arr, int n) {
  for (int i = 2; i < n; i++) {
    for (int j = 2 * i; j < n; j += i) {
      arr[j] = true;
    }
  }
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int p[n + 1], s[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  int c;
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    cin >> c;
    int e = 0;
    for (int i = 1; i <= n; i++) {
      if (s[i] == s[c]) {
        if (p[i] > p[c]) {
          e++;
        }
      }
    }
    if (e == 0) ans++;
  }
  cout << ans;
}
