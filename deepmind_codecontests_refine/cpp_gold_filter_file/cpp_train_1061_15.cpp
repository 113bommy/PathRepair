#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int inches = n / 3 + (n % 3 > 1);
  cout << inches / 12 << " " << inches % 12 << "\n";
  return 0;
}
