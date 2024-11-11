#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout.precision(10);
  int t = 1;
  while (t--) {
    int n, m, no1, no2;
    cin >> n >> m >> no1;
    set<int> second;
    for (int i = 0; i < no1; i++) {
      int x;
      cin >> x;
      second.insert(x);
    }
    cin >> no2;
    for (int i = 0; i < no2; i++) {
      int x;
      cin >> x;
      second.insert(x);
    }
    for (int i = 0; i < n * m * 1000; i++) {
      int a, b;
      a = i % n;
      b = i % m;
      if (second.find(a) != second.end() || second.find(b) != second.end()) {
        second.insert(a);
        second.insert(b);
      }
    }
    for (int i = 0; i < n; i++) {
      if (second.find(i) == second.end()) {
        cout << "No\n";
        return 0;
      }
    }
    for (int i = 0; i < m; i++) {
      if (second.find(i) == second.end()) {
        cout << "No\n";
        return 0;
      }
    }
    cout << "Yes\n";
  }
  return 0;
}
