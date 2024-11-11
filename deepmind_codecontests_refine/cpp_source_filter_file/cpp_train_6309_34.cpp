#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if ((n / k) % 2)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
