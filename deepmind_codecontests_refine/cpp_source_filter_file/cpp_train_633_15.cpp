#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long sol = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = i; j * i <= n; j++) {
      sol += j;
    }
  }
  cout << sol * 4 << endl;
}
