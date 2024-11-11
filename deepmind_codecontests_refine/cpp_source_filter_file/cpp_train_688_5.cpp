#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int f[1000];
  f[0] = f[1] = 1;
  for (int i = 2; i <= 1000; i++) f[i] = f[i - 1] + f[i - 2];
  long long n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    bool valid = true;
    for (int j = 0; j <= 1000; j++)
      if (i == f[j]) {
        valid = false;
        break;
      }
    if (valid)
      cout << "o";
    else
      cout << "O";
  }
  cout << endl;
  return 0;
}
