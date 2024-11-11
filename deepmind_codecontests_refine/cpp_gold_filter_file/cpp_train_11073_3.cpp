#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s;
  cin >> n;
  if (n < 3)
    cout << "-1";
  else
    for (int i = n; i >= 1; i--) {
      cout << i << " ";
    }
}
