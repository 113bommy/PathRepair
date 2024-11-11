#include <bits/stdc++.h>
using namespace std;
int const N = 11000;
int a[N], b[N];
int in[N], M;
int mx = 0;
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i] - k * i;
    if (b[i] >= 0) {
      in[b[i]]++;
      if (in[b[i]] > mx) {
        mx = in[b[i]];
        M = b[i];
      }
    }
  }
  cout << n - mx << endl;
  for (int i = 0; i < n; i++) {
    if (b[i] - M != 0) {
      if (b[i] - M < 0) {
        cout << "+ " << i + 1 << " " << -b[i] + M << endl;
      } else {
        cout << "- " << i + 1 << " " << b[i] - M << endl;
      }
    }
  }
  return 0;
}
