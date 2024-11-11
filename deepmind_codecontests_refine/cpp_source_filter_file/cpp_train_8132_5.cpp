#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main() {
  int n;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    cout << 9 * (a - 1) + b << endl;
  }
}
