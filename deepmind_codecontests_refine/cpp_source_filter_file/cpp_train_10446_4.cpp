#include <bits/stdc++.h>
using namespace std;
int main() {
  int w, h;
  long long cnt = 0;
  cin >> w >> h;
  for (int i = h - 1; i > 0; --i)
    for (int j = 1; j < w; ++j) cnt += (min(h - i, h) * min(w - j, j));
  cout << cnt;
  return 0;
}
