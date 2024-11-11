#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  long long int l = s.size(), lasta = 0, lastabefb = 0, i, ans;
  long long int arr[l + 1];
  arr[0] = 0;
  for (i = 0; i < l; i++) {
    if (s[i] == 'a') {
      arr[i + 1] = (1 + arr[lasta] + arr[lastabefb]) % 1000000007;
      lasta = i + 1;
      ans = arr[i + 1];
    } else if (s[i] == 'b') {
      lastabefb = lasta;
    }
  }
  cout << (ans + 1000000007) % 1000000007;
  return 0;
}
