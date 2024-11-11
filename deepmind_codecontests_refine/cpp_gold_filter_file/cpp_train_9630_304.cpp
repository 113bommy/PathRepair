#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long res = 0, cur = 1;
  while (n-- >= 3) {
    res += cur;
    cur += 2;
  }
  cout << res << endl;
}
