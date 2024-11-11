#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long int cur = 1;
  long long num = 1;
  while (cur != n) {
    if (cur != 1)
      cout << cur * 1ll * cur * 1ll * cur + 2 * cur * cur + 1;
    else
      cout << 2;
    cout << endl;
    cur++;
  }
  return 0;
}
