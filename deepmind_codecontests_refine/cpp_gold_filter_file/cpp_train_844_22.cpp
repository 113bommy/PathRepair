#include <bits/stdc++.h>
using namespace std;
int freq[100003];
void solve() {
  int n;
  cin >> n;
  int a[26];
  for (int i = 0; i < n; i++) {
    if (i % 4 == 0)
      cout << "a";
    else
      cout << (char)(97 + i % 4);
  }
}
int main() {
  int test = 1;
  while (test--) {
    solve();
  }
  return 0;
}
