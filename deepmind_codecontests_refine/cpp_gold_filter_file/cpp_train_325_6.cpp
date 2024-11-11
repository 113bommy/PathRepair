#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, n;
  string inp, str;
  cin >> n >> x >> y;
  cin >> inp;
  str = inp;
  int i;
  for (i = n - 1; i >= n - y; --i) {
    str[i] = '0';
  }
  str[i--] = '1';
  for (; i >= n - x; --i) {
    str[i] = '0';
  }
  int count = 0;
  for (int i = 0; i < n; ++i) {
    if (str[i] != inp[i]) count++;
  }
  cout << count << endl;
  return 0;
}
