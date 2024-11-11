#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  int cnt = 0;
  bool first = true;
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '0') {
      first = false;
    }
    if (first) {
      cnt++;
    }
  }
  cout << max(n, cnt + 1);
  return 0;
}
