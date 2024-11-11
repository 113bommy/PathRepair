#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ans = n / 5;
  int left = n % 5;
  ans += left / 4;
  left = left % 4;
  ans += left / 3;
  left = left % 3;
  ans += left / 2;
  left = left / 2;
  ans += left;
  cout << ans;
}
