#include <bits/stdc++.h>
using namespace std;
long long a, b, k, i;
int main() {
  cin >> a >> b;
  k = 1;
  if (a > b) {
    for (i = 1; i <= b; i++) {
      k = k * i;
    }
  } else {
    {
      for (i = 1; i <= a; i++) k = k * i;
    }
  }
  cout << k;
}
