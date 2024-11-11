#include <bits/stdc++.h>
using namespace std;
bool s[100005];
int main() {
  int n;
  cin >> n;
  n *= 2;
  int ans = 0, rst = 0;
  ;
  while (n--) {
    int tmp;
    cin >> tmp;
    if (s[tmp])
      ans -= 2;
    else
      s[tmp] = 1, ans++;
    rst = max(rst, ans);
  }
  cout << rst << endl;
  return 0;
}
