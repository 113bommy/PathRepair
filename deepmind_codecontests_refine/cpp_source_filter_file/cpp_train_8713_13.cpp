#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string a[n];
  for (int i = 0; i < n; ++i) cin >> a[i];
  string col[] = {"Power", "Space", "Time", "Soul", "Reality", "Mind"};
  string stone[] = {"purple", "blue", "green", "orange", "red", "yellow"};
  cout << n - 2 << "\n";
  for (int i = 0; i < 6; ++i) {
    int flag = 0;
    for (int j = 0; j < n; ++j) {
      if (stone[i] == a[j]) {
        flag = 1;
        break;
      }
    }
    if (!flag) {
      cout << col[i] << "\n";
    }
  }
  return 0;
}
