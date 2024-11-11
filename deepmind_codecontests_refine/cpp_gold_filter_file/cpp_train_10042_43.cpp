#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int num = sqrt(n * 2);
  if (n * 2 == num * (num + 1))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
