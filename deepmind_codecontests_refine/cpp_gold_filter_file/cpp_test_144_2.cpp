#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int z = 1; z <= t; z++) {
    int n, m, k;
    cin >> n >> m >> k;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
      q.push(i);
    }
    for (int i = 1; i <= k; i++) {
      int b = n % m;
      int a = m - b;
      int d = (n - 1) / m + 1;
      int d2 = n / m;
      for (int p = 1; p <= b; p++) {
        cout << d << ' ';
        for (int j = 1; j <= d; j++) {
          int val = q.front();
          cout << val << ' ';
          q.pop();
          q.push(val);
        }
        cout << "\n";
      }
      for (int p = 1; p <= a; p++) {
        cout << d2 << ' ';
        for (int j = 1; j <= d2; j++) {
          int val = q.front();
          cout << val << ' ';
          q.pop();
          q.push(val);
        }
        cout << "\n";
      }
      for (int p = 1; p <= b * d; p++) {
        int val = q.front();
        q.pop();
        q.push(val);
      }
    }
    cout << "\n";
  }
  return 0;
}
