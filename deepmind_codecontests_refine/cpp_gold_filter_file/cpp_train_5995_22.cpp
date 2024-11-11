#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long int INF = 1e17;
long long int c1[1025] = {0}, c2[1025] = {0};
int main() {
  ios_base::sync_with_stdio(0);
  long long int n, i, j, k, l, x;
  long long int N = 1025;
  cin >> n >> k >> x;
  long long int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    c1[a[i]]++;
  }
  for (i = 0; i < k; i++) {
    long long int ptr = 0;
    for (j = 0; j < N; j++) {
      if (ptr % 2 == 0) {
        if (c1[j] > 0) {
          if (c1[j] % 2 == 1) {
            c2[j ^ x] += c1[j] / 2 + 1;
            c2[j] += c1[j] / 2;
            ptr++;
          } else {
            c2[j ^ x] += c1[j] / 2;
            c2[j] += c1[j] / 2;
          }
        }
      } else {
        if (c1[j] > 0) {
          if (c1[j] % 2 == 1) {
            c2[j] += c1[j] / 2 + 1;
            c2[j ^ x] += c1[j] / 2;
            ptr++;
          } else {
            c2[j ^ x] += c1[j] / 2;
            c2[j] += c1[j] / 2;
          }
        }
      }
    }
    for (j = 0; j < N; j++) {
      c1[j] = c2[j];
      c2[j] = 0;
    }
  }
  long long int ma = INT_MIN, mi = INT_MAX;
  for (i = 0; i < N; i++) {
    if (c1[i] > 0) {
      ma = max(ma, i);
      mi = min(mi, i);
    }
  }
  cout << ma << " " << mi << endl;
  return 0;
}
