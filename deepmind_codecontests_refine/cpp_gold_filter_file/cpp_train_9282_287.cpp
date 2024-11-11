#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (a - n >= 0 && b - n >= 0) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}
