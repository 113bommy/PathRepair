#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  cout << 34 << endl;
  unsigned long long ans;
  for (int i = 3; i <= n + 1; ++i)
    cout << (unsigned long long)i * i * (i + 2) + 1LL << endl;
  return 0;
}
