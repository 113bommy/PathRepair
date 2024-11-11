#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int* cities = new int[n];
  int* towers = new int[m];
  for (int i = 0; i < n; i++) {
    scanf("%d", &cities[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &towers[i]);
  }
  int city_start = 0, tower_start = 0;
  long long r = -1, city_r = 10000000000, new_r;
  while (city_start < n) {
    if (tower_start < m) {
      new_r = abs(towers[tower_start] - cities[city_start]);
    } else {
      new_r = 10000000000;
    }
    if (new_r <= city_r) {
      city_r = new_r;
      tower_start++;
    } else {
      r = max(r, city_r);
      city_start++;
      tower_start--;
      city_r = 10000000000;
    }
  }
  cout << r << endl;
}
