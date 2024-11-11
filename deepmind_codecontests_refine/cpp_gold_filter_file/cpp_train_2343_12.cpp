#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, m;
  vector<int> hmap(1000200, 0);
  cin >> n;
  for (i = 0; i < n; i++) {
    scanf("%d", &m);
    hmap[m]++;
  }
  int count = 0;
  for (i = 0; i < 1000090; i++) {
    if (hmap[i] > 0) {
      hmap[i + 1] += hmap[i] / 2;
      if (hmap[i] % 2 == 1) count++;
    }
  }
  cout << count << '\n';
  return 0;
}
