#include <bits/stdc++.h>
using namespace std;
int a, b;
int main() {
  cin >> a >> b;
  if (a == 1 && b == 0) {
    cout << "NO";
    return 0;
  }
  if (abs(a - b) <= 1) {
    cout << "YES";
  } else
    cout << "NO";
  return 0;
}
