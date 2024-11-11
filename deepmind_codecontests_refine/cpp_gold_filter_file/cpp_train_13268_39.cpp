#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int count = 0;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    if (b - a > 1) count++;
  }
  cout << count << endl;
  return 0;
}
