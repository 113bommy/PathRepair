#include <bits/stdc++.h>
using namespace std;
int n, in;
map<int, int> m;
int a[250005], b[505], co;
int gcd(int h1, int h2) {
  if (h2 == 0) return h1;
  return gcd(h2, h1 % h2);
}
int main(int argc, char *argv[]) {
  cin >> n;
  for (int i = 0; i < n * n; i++) {
    cin >> a[i];
    m[a[i]]++;
  }
  for (map<int, int>::iterator it = m.end();;) {
    if (it == m.begin()) break;
    it--;
    if ((*it).second != 0) {
      int nub = 0;
      int nub2 = 0;
      for (int i = 0; i < co; i++) {
        if (b[i] % (*it).first == 0) {
          nub2++;
        }
      }
      while (2 * nub * nub2 + nub * nub < (*it).second) {
        nub++;
      }
      for (int i = 0; i < co; i++) {
        m[gcd(b[i], (*it).first)] -= 2;
      }
      for (int j = 0; j < nub; j++) {
        b[co] = (*it).first;
        co++;
      }
    }
  }
  for (int i = 0; i < co; i++) {
    printf("%d ", b[i]);
  }
  printf("\n");
  return 0;
}
