#include <bits/stdc++.h>
using namespace std;
int a, b;
int main() {
  cin >> a >> b;
  for (int i = 0; i <= b; ++i) {
    if (a % b == 0) {
      cout << "Yes";
      return 0;
    }
    a += (a % b);
    a %= b;
  }
  cout << "No";
}
