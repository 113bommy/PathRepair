#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, count = 0;
  cin >> a >> b >> c;
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    if (x > a && x < b) count++;
  }
  cout << count;
  return 0;
}
