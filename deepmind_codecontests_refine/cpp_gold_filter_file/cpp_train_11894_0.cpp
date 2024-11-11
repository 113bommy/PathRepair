#include <bits/stdc++.h>
using namespace std;
priority_queue<int> q;
int a[1001000];
int b[1001000];
int v[1001000];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n <= 3) {
      cout << -1 << endl;
      continue;
    }
    if (n == 4) {
      cout << "2 4 1 3" << endl;
      continue;
    }
    if (n == 5) {
      cout << "1 3 5 2 4" << endl;
      continue;
    }
    int j = 0;
    if (n % 2 == 1) {
      for (int i = 1; i <= n; i += 2) {
        b[j] = i;
        j++;
        v[i] = 1;
      }
      b[j] = b[j - 1] - 3;
      j++;
      v[b[j - 1]] = 1;
      while (!v[2]) {
        if (!v[b[j - 1] + 2] && b[j - 1] + 2 <= n) {
          b[j] = b[j - 1] + 2;
          j++;
          v[b[j - 1]] = 1;
        } else if (!v[b[j - 1] - 2] && b[j - 1] - 2 > 0) {
          b[j] = b[j - 1] - 2;
          v[b[j]] = 1;
          j++;
        } else if (!v[b[j - 1] - 4] && b[j - 1] - 4 > 0) {
          b[j] = b[j - 1] - 4;
          v[b[j]] = 1;
          j++;
        }
      }
      for (int i = 0; i < n; i++) {
        cout << b[i] << "  ";
        v[b[i]] = 0;
      }
    } else {
      for (int i = 2; i <= n; i += 2) {
        b[j] = i;
        j++;
        v[i] = 1;
      }
      b[j] = b[j - 1] - 3;
      j++;
      v[b[j - 1]] = 1;
      while (!v[1]) {
        if (!v[b[j - 1] + 2] && b[j - 1] + 2 <= n) {
          b[j] = b[j - 1] + 2;
          j++;
          v[b[j - 1]] = 1;
        } else if (!v[b[j - 1] - 2] && b[j - 1] - 2 > 0) {
          b[j] = b[j - 1] - 2;
          v[b[j]] = 1;
          j++;
        } else if (!v[b[j - 1] - 4] && b[j - 1] - 4 > 0) {
          b[j] = b[j - 1] - 4;
          v[b[j]] = 1;
          j++;
        }
      }
      for (int i = 0; i < n; i++) {
        cout << b[i] << "  ";
        v[b[i]] = 0;
      }
    }
    cout << endl;
    cout << endl;
  }
}
