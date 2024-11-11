#include <bits/stdc++.h>
using namespace std;
using lint = long long;
int lsum[1000100], rsum[1000100];
int main() {
  string str;
  cin >> str;
  int cnt = 0;
  for (int i = 1; i < str.size(); i++) {
    if (str[i - 1] == str[i] && str[i] == 'v') cnt++;
    lsum[i] = cnt;
  }
  cnt = 0;
  for (int i = str.size() - 2; i >= 0; i--) {
    if (str[i] == str[i + 1] && str[i] == 'v') cnt++;
    rsum[i] = cnt;
  }
  lint ans = 0;
  for (int i = 1; i < str.size() - 1; i++)
    if (str[i] == 'o') ans += lsum[i - 1] * rsum[i + 1];
  cout << ans << '\n';
}
