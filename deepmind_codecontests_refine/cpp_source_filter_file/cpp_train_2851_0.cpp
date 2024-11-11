#include <bits/stdc++.h>
using namespace std;
const long long BIGER = 1000000000000000;
const int BIG = 1000000000;
struct stru {
  int w, h;
};
stru book[101];
int a[101];
int b[101];
int main() {
  int n;
  cin >> n;
  int g1 = 0, g2 = 0;
  for (int i = 1; i <= n; i++) {
    cin >> book[i].w >> book[i].h;
    if (book[i].w == 1) a[++g1] = book[i].h;
    if (book[i].w == 2) b[++g2] = book[i].h;
  }
  sort(a + 1, a + 1 + g1);
  sort(b + 1, b + 1 + g2);
  int s1 = 0, s2 = 0;
  int mn = BIG;
  for (int i = 0; i <= g1; i++) {
    s1 += a[i];
    s2 = 0;
    for (int j = 0; j <= g2; j++) {
      s2 += b[j];
      if (s1 + s2 < g1 - i + g2 - j + g2 - j)
        mn = min(mn, g1 - i + g2 - j + g2 - j);
    }
  }
  cout << mn;
  return 0;
}
