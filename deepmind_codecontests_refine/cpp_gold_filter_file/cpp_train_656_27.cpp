#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    res += i * a;
  }
  cout << res << endl;
  return 0;
}
