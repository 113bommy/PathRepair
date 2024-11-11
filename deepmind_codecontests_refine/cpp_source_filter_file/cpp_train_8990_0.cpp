#include <bits/stdc++.h>
using namespace std;
typedef struct {
  int l, p;
} Song;
bool songCompare(Song a, Song b) {
  return a.p * (100 - b.p) * a.l > b.p * (100 - a.p) * b.l;
}
int main() {
  int n;
  Song s[50000];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s[i].l >> s[i].p;
  sort(s, s + n, songCompare);
  double r = 0, r2 = 0;
  for (int i = 0; i < n; i++) {
    r += s[i].l + r2 * ((100 - s[i].p) / 100.0);
    r2 += s[i].l * s[i].p / 100.0;
  }
  cout << setprecision(9) << r << endl;
}
