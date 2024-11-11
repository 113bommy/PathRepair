#include <bits/stdc++.h>
using namespace std;
int a[100];
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  char prev = '9', c = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != prev) {
      prev = s[i];
      c = 1;
    } else {
      c++;
    }
    if (c == k) {
      c = 0;
      a[s[i] - 97]++;
    }
  }
  int mx = 0;
  for (int i = 0; i < 50; i++) {
    if (a[i] > mx) {
      mx = a[i];
    }
  }
  cout << mx << endl;
  return 0;
}
