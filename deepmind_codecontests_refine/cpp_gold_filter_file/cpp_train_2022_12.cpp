#include <bits/stdc++.h>
using namespace std;
int B[(1 << 24) + 9100], a[19005];
string s;
int u[1000050];
int main() {
  int n, i, j;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> s;
    for (j = 0; j < 3; j++) a[i] |= (1 << (s[j] - 'a'));
    B[a[i]]++;
  }
  for (i = 0; i < 24; i++) {
    for (int mask = 0; mask < (1 << 24); mask++) {
      if ((mask & (1 << i))) {
        B[mask] += B[mask ^ (1 << i)];
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < 19000; i++) u[i] = i ^ B[i % n];
  for (int mask = 0; mask < (1 << 24); mask++) {
    long long temp = n - B[mask];
    temp *= temp;
    ans ^= temp;
  }
  cout << ans;
}
