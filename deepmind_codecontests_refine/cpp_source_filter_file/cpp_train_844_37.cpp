#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  string s[] = {"abcd", "a", "ab", "abc"};
  for (int i = 0; i < n / 4; i++) {
    cout << s[i];
  }
  if (n % 4 > 0) {
    cout << s[n % 4];
  }
  return 0;
}
