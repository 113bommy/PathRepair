#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  n = abs(n);
  for (long long i = 0, s = 0; i < 100; i++, s += i)
    if (s >= n && s % 2 == n % 2) {
      cout << i << endl;
      break;
    }
}
