#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  int count = 0;
  for (int i = 0; i < 5; i++) {
    int x = abs(a[i] - b[i]);
    if (x > 5) {
      count += (10 - x);
    } else {
      count += x;
    }
  }
  cout << count;
}
