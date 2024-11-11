#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  long long ans = k * pow(n - 1, k - 1);
  cout << ans << endl;
}
