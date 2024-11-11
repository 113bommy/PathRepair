#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    long long int start = 0;
    long long int end = 0;
    long long int l1 = -1100000000;
    long long int l2 = -1100000000;
    cin >> n;
    long long int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long int sum = 0;
    for (int i = 0; i < n; i++) {
      sum = sum + a[i];
    }
    long long int l = -1100000000;
    long long int s = 0;
    long long int p = 0;
    for (int i = 0; i < n; i++) {
      s = s + a[i];
      if (l < s) {
        l = s;
        start = p;
        end = i;
      }
      if (s < 0) {
        s = 0;
        p = i + 1;
      }
    }
    if (start == 0 && end == n - 1) {
      int s1 = 0;
      int p1 = 0;
      for (int i = 0; i < n - 1; i++) {
        s1 = s1 + a[i];
        if (l1 < s1) {
          l1 = s1;
          start = p1;
          end = i;
        }
        if (s1 < 0) {
          s1 = 0;
          p1 = i + 1;
        }
      }
      int s2 = 0;
      int p2 = 0;
      for (int i = 1; i < n; i++) {
        s2 = s2 + a[i];
        if (l2 < s2) {
          l2 = s2;
          start = p2;
          end = i;
        }
        if (s1 < 0) {
          s1 = 0;
          p1 = i + 1;
        }
      }
      l = max(l1, l2);
    }
    if (sum > l) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
