#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  cout << 2 << endl;
  unsigned long long ans;
  for (int i = 2; i <= n; ++i)
    cout << (unsigned long long)i * i * (i + 2) + 1LL << endl;
  return 0;
}
