#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    int result = sqrt(n);
    if (result * (result + 1) >= n)
      if (result * result >= n)
        result = result * 2 - 2;
      else
        result = result * 2 - 1;
    else
      result = result * 2;
    cout << result << endl;
  }
  return 0;
}
