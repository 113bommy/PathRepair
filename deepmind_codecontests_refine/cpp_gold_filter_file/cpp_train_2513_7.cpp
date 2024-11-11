#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  int sum = 0;
  string m = "";
  cin >> n;
  cin >> m;
  for (int i = 0; i < n; i++) {
    if (((int)m[i]) % 2 == 0) {
      sum += (i + 1);
    }
  }
  cout << sum;
}
