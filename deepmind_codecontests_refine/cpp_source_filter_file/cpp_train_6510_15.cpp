#include <bits/stdc++.h>
using namespace std;
long long pow2(int p) {
  long long res = 1;
  while (p--) res *= 2;
  return res;
}
int main() {
  int n;
  scanf("%d", &n);
  map<int, int> m1;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    m1[x]++;
  }
  int mov;
  scanf("%d", &mov);
  map<int, int> oud, sub;
  int mx1 = 0, res, mx2 = 0;
  vector<int> v;
  for (int i = 0; i < mov; i++) {
    int x;
    scanf("%d", &x);
    v.push_back(x);
  }
  for (int i = 0; i < mov; i++) {
    int y;
    scanf("%d", &y);
    int x = v[i];
    if ((m1[x] > mx1) || (m1[x] == mx1 && m1[y] > mx2)) {
      mx1 = m1[x];
      mx2 = m1[y];
      res = i + 1;
    }
  }
  printf("%d", res);
  return 0;
}
