#include <bits/stdc++.h>
using namespace std;
string str;
long long ans;
int main() {
  cin >> str;
  ans = 0;
  int p = 1;
  for (int i = str.length() - 1; i >= 0; i--) {
    if (str[i] == '0')
      ans = (ans * 2) % 1000000007;
    else {
      ans = ((2 * ans) % 1000000007 + p % 1000000007) % 1000000007;
    }
    p = (p * 4) % 1000000007;
  }
  cout << ans;
}
