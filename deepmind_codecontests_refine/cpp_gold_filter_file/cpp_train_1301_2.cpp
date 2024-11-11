#include <bits/stdc++.h>
using namespace std;
bool m(int i, int j) { return (i % 10) > (j % 10); }
int main() {
  int x, y;
  cin >> y >> x;
  vector<int> vi;
  int i = 0, j = 0;
  int k = 0;
  for (i = 0; i < y; i++) {
    cin >> j;
    k += (j % 10);
    vi.push_back(j);
  }
  sort(vi.begin(), vi.begin() + y, m);
  for (i = 0; i < y && x > 0; i++) {
    k = (10 - (vi[i] % 10));
    if (x >= k && (vi[i] + k) <= 100) {
      x -= k;
      vi[i] += k;
    }
  }
  for (i = 0; i < y && x > 0; i++) {
    while ((vi[i] < 100) && (x >= 10)) {
      vi[i] += 10;
      x -= 10;
    }
  }
  k = 0;
  for (i = 0; i < y; i++) k += vi[i] / 10;
  cout << k << " ";
  return EXIT_SUCCESS;
}
