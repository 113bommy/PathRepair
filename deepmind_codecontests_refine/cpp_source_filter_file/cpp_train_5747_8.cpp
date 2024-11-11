#include <bits/stdc++.h>
using namespace std;
long long n;
int first = -1, ans = 0;
int main() {
  cin >> n;
  for (long long i = 2; i * i <= n; ++i)
    if (n % i == 0) {
      if (first == -1) first = (int)i;
      ++ans;
      while (n % i == 0) n /= i;
    }
  if (n != 1 && first == -1) first = (int)n;
  if (n != 1) ++ans;
  if (ans == 1)
    cout << first << endl;
  else if (ans == 0)
    cout << n << endl;
  else
    cout << 1 << endl;
  return 0;
}
