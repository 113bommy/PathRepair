#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  int count = 1;
  cin >> n >> a;
  if (a % 2 == 0) {
    count += (n - a) / 2;
  } else {
    b = n - (a - 1);
    count += (n - b) / 2;
  }
  cout << count << endl;
  return 0;
}
