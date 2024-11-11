#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> ind(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i]) {
      ind[a[i]] = -1;
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if (b[i]) {
      ind[b[i]] = i;
    }
  }
  bool check = false;
  bool p = false;
  int M = 0;
  int last = -1;
  if (ind[1] == -1) {
    for (int i = 2; i <= n; i++) {
      if (ind[i] != -1) {
        if (ind[i] - i + 2 > 0) {
          M = max(M, ind[i] - i + 2);
        }
      }
    }
    cout << n + M;
  } else {
    int kek = 0;
    for (int i = 0; i < n; i++) {
      if (p) {
        break;
      }
      if (b[i] == 1) {
        last = b[i];
        kek = i;
        p = true;
        check = true;
        for (int j = i + 1; j < n; j++) {
          last = b[j];
          if (b[j] != j - i + 1) {
            check = false;
            break;
          }
        }
      }
    }
    if (check) {
      bool uu = true;
      for (int i = 0; i < kek; i++) {
        if (ind[b[i]] != -1 && b[i] != 0) {
          if (b[i] - ind[b[i]] - 2 - last < 0) {
            uu = false;
            break;
          }
        }
      }
      if (uu) {
        cout << n - last;
      } else {
        cout << n + kek + 1;
      }
    } else {
      for (int i = 2; i <= n; i++) {
        if (ind[i] != -1) {
          int k = i - 1;
          if (M, ind[i] - kek - k > 0) {
            M = max(M, ind[i] - kek - k);
          }
        }
      }
      cout << n + kek + 1 + M + 1;
    }
  }
  return 0;
}
