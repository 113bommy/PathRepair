#include <bits/stdc++.h>
using namespace std;
const long long INF = (1ll << 62) - 1;
const int inf = (1 << 30) - 1;
int sod(int p) {
  int ad = 0;
  while (p) {
    ad += p % 10;
    p /= 10;
  }
  return ad;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, m, a, b, f = 0;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < 1000; i++) cout << 5 << " ";
  cout << endl;
  for (int i = 0; i < 999; i++) cout << 4 << " ";
  cout << 5;
  return 0;
}
