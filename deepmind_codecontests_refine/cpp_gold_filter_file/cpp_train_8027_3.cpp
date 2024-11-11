#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 100000 + 5;
int a[N];
int target[N] = {0};
int p = 0;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p += a[i];
  }
  if (p % m) {
    cout << "No";
    return 0;
  }
  int sum = p / m;
  if (m == 1) {
    cout << "Yes" << endl;
    cout << n;
    return 0;
  }
  int pk = 0;
  int mm = m;
  while (m--) {
    int s = 0, ok = false;
    for (int i = target[pk] + 1; i <= n; ++i) {
      s += a[i];
      if (s == sum) {
        target[++pk] = i;
        ok = true;
        break;
      }
      if (s > sum) {
        cout << "No";
        return 0;
      }
    }
    if (!ok) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes" << endl;
  for (int i = 1; i <= mm; ++i) {
    cout << target[i] - target[i - 1] << " ";
  }
  return 0;
}
