#include <bits/stdc++.h>
using namespace std;
void testcase() {
  int n;
  cin >> n;
  long long res = 1;
  for (int i = 0; i < n - 2; i++) {
    res += (n - i) * (n - i - 1);
  }
  cout << res;
}
int main() { testcase(); }
