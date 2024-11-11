#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  int c[n + 1];
  for (long long i = 1; i <= n; i++) cin >> c[i];
  int result = 0;
  for (int i = 1; i <= n; ++i)
    if (c[i] != c[n] || c[1] != c[n - i + 1]) {
      result = n - i;
      break;
    }
  cout << result;
}
