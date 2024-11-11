#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  cout << 2 << endl;
  for (long long i = 3; i <= n + 1; i++)
    cout << (i - 1) * (i * i) - i + 2 << endl;
  return 0;
}
