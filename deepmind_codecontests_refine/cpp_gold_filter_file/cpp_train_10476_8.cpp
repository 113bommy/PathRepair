#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const int N = 1e6 + 10;
int a[N];
int main() {
  string str;
  cin >> str;
  int sum = 0;
  for (auto &c : str) sum += c == 'Q';
  int s = 0;
  int ans = 0;
  for (auto &c : str) {
    if (c == 'A')
      ans += s * (sum - s);
    else if (c == 'Q')
      s++;
  }
  cout << ans << endl;
  return 0;
}
