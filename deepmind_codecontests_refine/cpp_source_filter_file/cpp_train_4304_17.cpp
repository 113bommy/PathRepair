#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long s = 0;
  cin >> n;
  n--;
  s = 1;
  for (int i = 1; i <= n; i++) {
    s += 12;
  }
  cout << s;
  return 0;
}
