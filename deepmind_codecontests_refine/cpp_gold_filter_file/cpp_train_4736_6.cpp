#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, k;
  cin >> n >> k;
  long c;
  cin >> c;
  vector<long> mass(c);
  for (long i = 0; i < c; i++) cin >> mass[i];
  mass.push_back(1000000000);
  long kol = c;
  long now = 0, now1 = -1;
  while (now + k <= n) {
    if (now + k < mass[now1 + 1]) {
      now += k;
      kol++;
    } else
      now = mass[++now1];
  }
  cout << kol;
  return 0;
}
