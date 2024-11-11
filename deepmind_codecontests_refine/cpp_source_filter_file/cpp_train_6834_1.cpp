#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
  cin >> n;
  if (n == 0) {
    cout << "1" << endl;
    return 0;
  }
  if (n > 34) {
    cout << -1 << endl;
    return 0;
  }
  int cont = 17;
  string ans;
  while (n > 0 && cont > 0) {
    if (n >= 2) {
      n -= 2;
      ans.push_back('8');
    } else {
      if (n >= 1) {
        n--;
        ans.push_back('4');
      }
    }
    cont--;
  }
  cout << ans << endl;
  return 0;
}
