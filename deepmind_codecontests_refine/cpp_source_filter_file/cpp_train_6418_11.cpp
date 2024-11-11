#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a = 0, b = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (t > 0)
      a++;
    else
      b++;
  }
  cout << a - b << endl;
  return 0;
}
