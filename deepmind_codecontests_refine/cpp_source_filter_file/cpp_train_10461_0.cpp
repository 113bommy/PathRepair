#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, w;
  long long n;
  long long f = 0;
  cin >> k >> n >> w;
  for (int i = 1; i <= w; i++) {
    f = f + k * i;
  }
  if (f == w) {
    cout << "0";
  } else {
    cout << f - n;
  }
  return 0;
}
