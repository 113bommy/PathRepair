#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, num;
  cin >> n >> k;
  num = (n) * (n - 1) / 2;
  if (num <= k)
    cout << "no solution" << endl;
  else
    for (int i = 1; i <= n; i++) cout << 1 << " " << i << endl;
}
