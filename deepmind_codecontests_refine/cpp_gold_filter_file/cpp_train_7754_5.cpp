#include <bits/stdc++.h>
using namespace std;
int b[10000];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < (int)(n); i++) b[i] = 0;
  int s = 0;
  b[0] = 1;
  for (int i = 0; i < (int)(10 * n + 10); i++) {
    s += i;
    s %= n;
    b[s] = 1;
  }
  for (int i = 0; i < (int)(n); i++)
    if (!b[i]) {
      cout << "NO";
      return 0;
    }
  cout << "YES";
  return 0;
}
