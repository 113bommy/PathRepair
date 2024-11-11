#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, d = 0;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    int temp;
    cin >> temp;
    if (c == '+')
      x += temp;
    else {
      if (temp > x)
        d += 1;
      else
        x -= temp;
    }
  }
  cout << x << " " << d;
}
