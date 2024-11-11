#include <bits/stdc++.h>
using namespace std;
bool check_Lower(string str, int n) {
  for (int j = 0; j < n; j++) {
    if (str[j] >= str[j + n]) return false;
  }
  return true;
}
bool check_Upper(string str, int n) {
  for (int j = 0; j < n; j++) {
    if (str[j] <= str[j + n]) return false;
  }
  return true;
}
int main() {
  int n;
  bool low = false;
  bool up = false;
  string str;
  cin >> n;
  cin >> str;
  sort(str.begin(), str.begin() + (n - 1));
  sort(str.begin() + n, str.end());
  low = check_Lower(str, n);
  up = check_Upper(str, n);
  if (low || up) {
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
  return 0;
}
