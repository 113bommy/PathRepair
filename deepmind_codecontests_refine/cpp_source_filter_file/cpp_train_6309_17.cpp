#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int t = n / k;
  if (t % 2 == 0)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
