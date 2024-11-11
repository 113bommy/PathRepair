#include <bits/stdc++.h>
using std::pair;
const double PI = acos(-1);
const int N = 300000 + 10;
const int M = 100 + 10;
const int INF = 0x3f3f3f3f;
using namespace std;
int main() {
  int n, s;
  int h[M], m[M];
  cin >> n >> s;
  h[0] = 0;
  m[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> h[i] >> m[i];
  }
  int f = 0;
  for (int i = 1; i <= n; i++) {
    int mi = (h[i] - h[i - 1]) * 60 + m[i] - m[i - 1];
    if (i == 1 && mi >= s + 1) {
      cout << "0 0" << endl;
      f = 1;
      break;
    } else if (mi >= 2 * s + 2) {
      int mii = h[i - 1] * 60 + m[i - 1] + s + 1;
      int hh = mii / 60;
      int mm = mii % 60;
      cout << hh << " " << mm << endl;
      f = 1;
      break;
    }
  }
  if (f == 0) {
    int mii = h[n - 1] * 60 + m[n - 1] + s + 1;
    int hh = mii / 60;
    int mm = mii % 60;
    cout << hh << " " << mm << endl;
  }
}
