#include <bits/stdc++.h>
using namespace std;
int p[200000], q[200001] = {0};
int main() {
  int t, n;
  long long w;
  cin >> t;
  while (t--) {
    cin >> n >> w;
    long long d;
    d = (w + 1) / 2;
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    int a = 0;
    long long sum = 0;
    bool flag = 0, flag1 = 0;
    for (int i = 0; i < n; i++) {
      if (p[i] <= w) {
        if (p[i] >= d) {
          cout << 1 << endl;
          cout << i + 1 << endl;
          flag = 1;
          break;
        }
        sum += p[i];
        q[a++] = i + 1;
        if (sum >= d) {
          flag1 = 1;
          break;
        }
      }
    }
    if (flag) {
      continue;
    }
    if (flag1) {
      cout << a - 1 << endl;
      for (int i = 0; i < a; i++) {
        cout << q[i] << ' ';
      }
      cout << endl;
      continue;
    }
    if (sum < d) {
      cout << -1 << endl;
      continue;
    }
  }
}
