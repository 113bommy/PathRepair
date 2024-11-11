#include <bits/stdc++.h>
using namespace std;
int D[110], n, s;
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    int h, m;
    cin >> h >> m;
    D[i] = h * 60 + m;
  }
  D[n] = 0x3f3f3f3f;
  int resph, respm, resp, ind = 1;
  if (s >= D[0])
    for (int i = 0; i < n; i++) {
      if (D[i + 1] - D[i] > 2 * s + 1 && ind) {
        resp = D[i] + s + 1;
        ind = 0;
      }
    }
  else
    resp = 0;
  respm = resp % 60;
  resph = (resp - respm) / 60;
  cout << resph << " " << respm << endl;
}
