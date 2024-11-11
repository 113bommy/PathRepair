#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k, i, j, temp, y = 0;
  cin >> n >> k;
  temp = n * (n - 1) / 2;
  if (temp < k)
    cout << "no solution";
  else {
    while (n--) {
      cout << 0 << ' ' << y++ << endl;
    }
  }
}
