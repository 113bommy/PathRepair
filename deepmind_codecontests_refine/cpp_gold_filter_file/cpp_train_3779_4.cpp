#include <bits/stdc++.h>
using namespace std;
int N = 10000 + 10;
int cnt74, cnt47;
int main() {
  string a, b;
  getline(cin, a);
  getline(cin, b);
  int n = a.length();
  for (int i = 0; i < n; i++) {
    if (a[i] == '7' && b[i] == '4') {
      cnt74++;
    }
    if (a[i] == '4' && b[i] == '7') {
      cnt47++;
    }
  }
  cout << max(cnt74, cnt47);
  return 0;
}
