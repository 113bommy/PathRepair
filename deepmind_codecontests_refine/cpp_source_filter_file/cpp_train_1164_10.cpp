#include <bits/stdc++.h>
using namespace std;
map<long long, long long> b;
int main() {
  int n, k, c = 0;
  string x;
  cin >> n >> k >> x;
  if (x[0] == '4' && x[1] == '7') {
    x[0] = x[1] = '4';
    k--;
  }
  for (int i = 1; k > 0 && i < n - 1; i++) {
    if (x[i] == '4' && x[i + 1] == '7') {
      if (i % 2) {
        if (x[i - 1] == '4') {
          if (k % 2 != 0)
            x[i] = '7';
          else
            x[i] = '4';
          break;
        } else
          x[i] = x[i + 1] = '7';
      } else
        x[i] = x[i + 1] = '4';
      k--;
    }
  }
  cout << x << endl;
}
