#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int a[n], c[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    c[i] = a[i];
  }
  sort(c, c + n);
  int count = distance(c, unique(c, c + n));
  int c_size = sizeof(c) / sizeof(c[0]);
  if (count >= k) {
    cout << "YES" << endl;
    for (int i = 0; i < count; i++) {
      auto t = find(a, a + n, c[i]);
      cout << distance(a, t) + 1 << ' ';
    }
  } else
    cout << "NO";
}
