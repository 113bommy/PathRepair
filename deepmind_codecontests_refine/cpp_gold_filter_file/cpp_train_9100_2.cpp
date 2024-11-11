#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n >> x;
  int offset = 0;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    offset += temp;
  }
  offset = abs(offset);
  int out = (offset - 1) / x + 1;
  if (offset == 0) {
    out = 0;
  }
  cout << out;
}
