#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s = 0;
  cin >> n;
  while (n--) {
    int a, b, c;
    cin >> a >> b >> c;
    int sum = a + b + c;
    if (sum >= 2) s++;
  }
  cout << s << endl;
  return 0;
}
