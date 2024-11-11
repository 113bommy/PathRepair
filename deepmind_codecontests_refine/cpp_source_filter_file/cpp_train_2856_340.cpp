#include <bits/stdc++.h>
using namespace std;
int ans[16] = {1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0};
int main() {
  int a;
  cin >> a;
  cout << ans[a - 1];
}
