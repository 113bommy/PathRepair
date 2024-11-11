#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long a[n][n];
  for (long long r = 0; r < n; r++) {
    for (long long c = 0; c < n; c++) {
      cin >> a[r][c];
    }
  }
  vector<long long> cnt;
  for (long long r = 0; r < n; r++) {
    bool mmd = true;
    for (long long c = 0; c < n; c++) {
      if (a[r][c] == 2 || a[r][c] == 3) {
        mmd = false;
        break;
      }
    }
    if (mmd) {
      cnt.push_back(r + 1);
    }
  }
  cout << cnt.size() << "\n";
  for (int i = 0; i < cnt.size(); i++) {
    cout << cnt[i] << " ";
  }
}
