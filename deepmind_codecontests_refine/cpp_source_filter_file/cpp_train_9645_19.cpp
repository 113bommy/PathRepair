#include <bits/stdc++.h>
using namespace std;
int n, ans = 0;
bool check[100] = {
    false,
};
int main() {
  cin >> n;
  int tmp;
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    if (tmp > 0 && !check[tmp]) {
      ans++;
      check[tmp] = true;
    }
  }
  cout << ans;
  return 0;
}
