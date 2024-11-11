#include <bits/stdc++.h>
using namespace std;
bool decreasing(int a, int b) { return a > b; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int num[10] = {2, 7, 3, 3, 3, 4, 2, 5, 1, 2};
  int n;
  cin >> n;
  cout << (num[n % 10] * num[(n / 10) % 10]) << '\n';
  return 0;
}
