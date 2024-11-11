#include <bits/stdc++.h>
using namespace std;
long long i, j, c;
int main() {
  long long w, h;
  cin >> w >> h;
  for (i = 1; i < w; i++) {
    for (j = 1; j < h; j++) {
      c += min(min(i, w - i), min(j, h - j));
    }
  }
  cout << c;
  return 0;
}
