#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, r, l;
  int mins = 0, maxs = 0;
  cin >> n >> l >> r;
  int mx = (int)pow(2, (r - 1));
  int mn = (int)pow(2, (l - 1));
  int l1 = l - 1;
  mn = mn * 2;
  while (l1 != 0) {
    mn = mn / 2;
    mins = mins + (mn);
    l1--;
  }
  mins = mins + (n - (l - 1));
  int r1 = r - 1;
  int mx1 = mx * 2;
  while (r1 != 0) {
    mx1 = mx1 / 2;
    maxs = maxs + mx1;
    r1--;
  }
  maxs = maxs + 1 + (mx * (n - r));
  cout << mins << " " << maxs;
}
