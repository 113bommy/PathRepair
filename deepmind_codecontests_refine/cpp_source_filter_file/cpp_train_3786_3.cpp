#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int, int>, int> > mir[2];
bool zuzyte[2][110];
int main() {
  int hl, hr, n;
  scanf("%d %d %d", &hl, &hr, &n);
  for (int i = 1; i <= n; i++) {
    int v, a, b;
    char c;
    scanf("%d %c %d %d", &v, &c, &a, &b);
    if (c == 'T')
      mir[0].push_back(make_pair(make_pair(a, b), v));
    else
      mir[1].push_back(make_pair(make_pair(a, b), v));
  }
  int WYN = -1;
  for (int i = -110; i <= 110; i++) {
    if (i == 0) continue;
    int cel = hr + 100 * i;
    if (abs(i) % 2) cel += 100 - 2 * hr;
    double b = hl;
    double a = cel - hl;
    a /= 100000.0;
    int wyn = 0;
    bool znaleziono = 1;
    if (cel >= 100) {
      bool pow = 0;
      for (int j = 0; j <= 1; j++)
        for (int I = 0; I < mir[j].size(); I++) zuzyte[j][I] = false;
      for (int y = 100; y < cel; y += 100) {
        double x = ((double)y) - b;
        znaleziono = false;
        x /= a;
        for (vector<pair<pair<int, int>, int> >::iterator it = mir[pow].begin();
             it != mir[pow].end(); it++) {
          if (((double)it->first.first <= x) &&
              (x <= (double)it->first.second)) {
            if (zuzyte[pow][it - mir[pow].begin()]) break;
            znaleziono = true;
            wyn += it->second;
            zuzyte[pow][it - mir[pow].begin()] = true;
            break;
          }
        }
        if (!znaleziono) break;
        pow = !pow;
      }
    } else {
      bool pow = 1;
      for (int j = 0; j <= 1; j++)
        for (int I = 0; I < mir[j].size(); I++) zuzyte[j][I] = false;
      for (int y = 0; y > cel; y -= 100) {
        double x = ((double)y) - b;
        znaleziono = false;
        x /= a;
        for (vector<pair<pair<int, int>, int> >::iterator it = mir[pow].begin();
             it != mir[pow].end(); it++) {
          if (it->first.first <= x && x <= it->first.second) {
            if (zuzyte[pow][it - mir[pow].begin()]) break;
            znaleziono = true;
            wyn += it->second;
            zuzyte[pow][it - mir[pow].begin()] = true;
            break;
          }
        }
        if (!znaleziono) break;
        pow = !pow;
      }
    }
    if (znaleziono) WYN = max(WYN, wyn);
  }
  printf("%d\n", WYN);
}
