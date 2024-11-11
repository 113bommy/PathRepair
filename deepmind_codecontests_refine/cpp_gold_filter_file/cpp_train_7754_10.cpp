#include <bits/stdc++.h>
using namespace std;
const int oo = 1001;
bool mark[oo];
int main() {
  int n, p = 0;
  cin >> n;
  mark[0] = true;
  for (int i = 1; i <= n; i++) {
    p += i;
    p %= n;
    mark[p] = true;
  }
  for (int i = 1; i < n; i++) {
    if (!mark[i]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
