#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string str;
  cin >> n >> str;
  int ans = INT_MAX;
  for (int i = 0; i < n; i++) {
    rotate(str.begin(), str.begin() + i, str.end());
    int nh = count(str.begin(), str.end(), 'H');
    int x = 0;
    for (int j = 0; j < nh; j++) x += str[j] == 'H';
    ans = min(ans, nh - x);
    int nt = count(str.begin(), str.end(), 'T');
    int y = 0;
    for (int j = 0; j < nt; j++) y += str[j] == 'T';
    ans = min(ans, nt - y);
  }
  printf("%d\n", ans);
  return 0;
}
