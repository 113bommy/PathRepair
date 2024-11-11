#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, ans;
  cin >> n;
  if (n == 3)
    cout << "1";
  else if (n == 4)
    cout << "2";
  else {
    ans = n + (n - 4) * (n - 1);
    cout << ans;
  }
}
