#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string* s = new string[n];
  for (int i = 0; i < n; i++) cin >> s[i];
  int mx = 1;
  for (int i = 0; i < 7; i++) {
    int a = 0;
    for (int j = 0; j < n; j++) {
      a += (s[j][i] - 48);
    }
    if (mx < a) mx = a;
  }
  cout << mx;
}
