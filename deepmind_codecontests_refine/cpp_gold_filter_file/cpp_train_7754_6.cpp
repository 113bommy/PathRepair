#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n & (n - 1))
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
