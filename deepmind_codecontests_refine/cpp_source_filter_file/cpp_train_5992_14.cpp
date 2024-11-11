#include <bits/stdc++.h>
using namespace std;
bool used[100];
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int s = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    s += a[i];
  }
  int cnt = s / n * 2;
  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      used[i] = true;
      for (int j = 0; j < n; ++j) {
        if (!used[j] && a[i] + a[j] == cnt) {
          used[j] = true;
          cout << i + 1 << ' ' << j + 1 << endl;
          break;
        }
      }
    }
  }
  return 0;
}
