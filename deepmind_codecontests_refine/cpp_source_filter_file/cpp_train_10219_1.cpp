#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, q;
  cin >> n >> q;
  long long a[q];
  map<long long, long long> m, p;
  long long fans = 0;
  for (int i = 0; i < q; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < q; i++) {
    if (m.find(a[i]) == m.end()) {
      m[a[i]] = i;
    }
  }
  for (int i = q - 1; i > -1; i--) {
    if (p.find(a[i]) == p.end()) {
      p[a[i]] = i;
    }
  }
  if (n == 1) {
    cout << "0\n";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (m.find(i) == m.end()) {
      fans++;
      m[i] = n;
    }
    long long end1 = i + 1;
    long long end2 = i - 1;
    long long indx = m[i];
    if (i == 1) {
      if (p.find(end1) == p.end()) {
        fans++;
      } else {
        long long indx1 = p[end1];
        if (indx1 <= indx) {
          fans++;
        }
      }
    } else if (i == n) {
      long long indx2 = p[end2];
      if (indx2 <= indx) {
        fans++;
      }
    } else {
      if (p.find(end1) == p.end()) {
        fans++;
      } else {
        long long indx1 = p[end1];
        if (indx1 <= indx) {
          fans++;
        }
      }
      long long indx2 = p[end2];
      if (indx2 <= indx) {
        fans++;
      }
    }
  }
  cout << fans;
}
