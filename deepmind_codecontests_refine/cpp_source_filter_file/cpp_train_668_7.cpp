#include <bits/stdc++.h>
using namespace std;
void solve() {
  string str;
  cin >> str;
  vector<long long> a(2, 0);
  vector<long long> b(2, 0);
  int oddCount = 0, evenCount = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == 'a') {
      if (i % 2 == 1) {
        oddCount += a[1];
        evenCount += a[0];
      } else {
        oddCount += a[0];
        evenCount += a[1];
      }
      a[i % 2]++;
    } else {
      if (i % 2 == 1) {
        oddCount += b[1];
        evenCount += b[0];
      } else {
        oddCount += b[0];
        evenCount += b[1];
      }
      b[i % 2]++;
    }
  }
  oddCount += str.length();
  cout << evenCount << " " << oddCount << endl;
}
int main() {
  solve();
  return 0;
}
