#include <bits/stdc++.h>
using namespace std;
struct cc {
  int first;
  int second;
};
bool io(cc x, cc y) { return x.first < y.first; }
int main() {
  int n;
  cin >> n;
  int k;
  cin >> k;
  cc a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  int b[n];
  for (int i = 0; i < n; i++) {
    b[i] = a[i].first;
  }
  if (n == 1) {
    cout << 0 << ' ' << 0;
    return 0;
  }
  int m = 0;
  while (k--) {
    sort(b, b + n);
    if (b[0] == b[n - 1] || b[n - 1] == b[0] + 1) {
      break;
    }
    m++;
    b[0]++;
    b[n - 1]--;
  }
  sort(b, b + n);
  cout << b[n - 1] - b[0] << ' ' << m << endl;
  while (m--) {
    sort(a, a + n, io);
    cout << a[n - 1].second << ' ' << a[0].second << endl;
    a[0].first++;
    a[n - 1].first--;
  }
}
