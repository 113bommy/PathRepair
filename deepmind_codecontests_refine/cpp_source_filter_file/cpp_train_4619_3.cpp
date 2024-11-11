#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  int a, b, c;
  int result;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c;
    result += (a + b + c >= 2);
  }
  cout << result;
  return 0;
}
