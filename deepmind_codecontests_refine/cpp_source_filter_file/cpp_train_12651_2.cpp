#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, like[1000000];
int main() {
  cin >> n;
  while (n--) {
    cin >> c;
    like[c]++;
    if (a < like[c]) a = like[c], b = c;
  }
  cout << b;
}
