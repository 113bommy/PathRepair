#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], b[n];
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      a[i] = 2 * i + 1;
      b[i] = a[i] + 1;
    } else {
      a[i] = 2 * (i + 1);
      b[i] = a[i] - 1;
    }
    sum += a[i];
  }
  int c[2 * n];
  for (int i = 0; i < n; i++) c[i] = a[i];
  for (int i = n; i < 2 * n; i++) c[i] = b[i - n];
  set<int> s;
  s.insert(sum);
  int i = 1;
  for (; i < 2 * n; i++) {
    sum = sum - c[i - 1] + c[(i + n - 1) % (2 * n)];
    s.insert(sum);
    if (s.size() > 2) break;
  }
  if (i != 2 * n)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    for (int i = 0; i < 2 * n; i++) cout << c[i] << " ";
    cout << endl;
  }
}
