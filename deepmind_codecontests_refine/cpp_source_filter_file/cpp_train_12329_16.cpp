#include <bits/stdc++.h>
using namespace std;
unsigned long long s;
int main() {
  int n;
  cin >> n;
  for (unsigned long long i = 1; i <= n; ++i) {
    char c;
    cin >> c;
    if (c == 'B') s += 1 << (i - 1);
  }
  cout << s;
  return 0;
}
