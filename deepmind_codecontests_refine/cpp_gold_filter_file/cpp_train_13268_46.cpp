#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int count = 0, a, b;
  while (n--) {
    cin >> a >> b;
    if (b - a >= 2) {
      count++;
    }
  }
  cout << count;
  return 0;
}
