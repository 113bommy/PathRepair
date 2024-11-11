#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n;
  cin >> n >> a >> b;
  int temp = n - a;
  if (temp > b) {
    cout << b + 1;
  } else {
    cout << temp;
  }
  return 0;
}
