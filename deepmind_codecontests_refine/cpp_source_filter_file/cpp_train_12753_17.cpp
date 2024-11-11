#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  float dist, h, w, t;
  cin >> dist;
  cin >> h;
  cin >> w;
  t = dist / (h + w);
  printf("%.1lf\n", t * h);
  return 0;
}
