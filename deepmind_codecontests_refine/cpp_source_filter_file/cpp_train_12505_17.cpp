#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  if (n == 1) {
    cout << -1;
    return 0;
  }
  if (n % 2) {
    n++;
  }
  cout << n << " " << 2;
  return 0;
}
