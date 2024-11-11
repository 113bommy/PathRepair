#include <bits/stdc++.h>
using namespace std;
vector<long long> L;
long long x = 0, l, r, a, b;
long long res;
int Init() {
  if (x <= 1000000000)
    L.push_back(x * 10 + 4), L.push_back(x * 10 + 7);
  else
    return 0;
  x = x * 10 + 7;
  Init();
  x = x / 10;
  x = x * 10 + 4;
  Init();
  x = x / 10;
  return 0;
}
long long Get(long long key) {
  for (long long i = 0; i < L.size(); i++)
    if (L[i] >= key) return i;
}
int main() {
  Init();
  sort(L.begin(), L.end());
  cin >> l >> r;
  a = Get(l);
  b = Get(r);
  res = 0;
  x = l - 1;
  for (int i = a; i <= b; i++) {
    res += (min(L[i], r) - x) * L[i];
    x = L[i];
  }
  cout << res;
}
