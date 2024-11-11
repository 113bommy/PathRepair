#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n, w;
  cin >> k >> n >> w;
  int temp = 0, b;
  for (int i = 1; i <= w; ++i) {
    temp += i * k;
  }
  if (temp < n)
    cout << 0 << endl;
  else
    cout << temp << endl;
  return 0;
}
