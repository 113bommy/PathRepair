#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[5] = {0};
  for (int i = 1; i <= 4; i++) cin >> a[i];
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    int c = s[i] - '0';
    cnt += a[c];
  }
  cout << cnt;
}
