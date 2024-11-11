#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  for (int e = 0; e < m; e++) {
    int k, p;
    cin >> k >> p;
    vector<int> b;
    for (int i = 0; i < k; i++) {
      b.push_back(a[i]);
    }
    for (int i = k; i < n; i++) {
      int MIN = 1000000007, pos = 0;
      for (int j = 0; j < k; j++) {
        if (b[j] <= MIN) {
          MIN = b[j];
          pos = j;
        }
      }
      if (a[i] > MIN) {
        b.erase(b.begin() + pos);
        b.push_back(a[i]);
      }
    }
    cout << b[p - 1] << endl;
  }
}
