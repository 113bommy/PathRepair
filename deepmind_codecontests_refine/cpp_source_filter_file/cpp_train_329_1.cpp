#include <bits/stdc++.h>
using namespace std;
long long n, p, w, d;
long long win, draw, lose;
void ans() {
  for (draw = 0; draw < w; draw++) {
    if ((p - d * draw) % w) continue;
    win = (p - d * draw) / w;
    lose = n - win - lose;
    if (win < 0 || lose < 0) continue;
    cout << win << " " << draw << " " << lose << endl;
    return;
  }
  cout << -1 << endl;
}
int main() {
  while (cin >> n >> p >> w >> d) {
    ans();
  }
  return 0;
}
