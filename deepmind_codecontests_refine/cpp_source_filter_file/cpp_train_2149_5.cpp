#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int x = n / 2;
  int y = n / 2 + 1;
  cout << (x + 1) * y;
  return 0;
}
