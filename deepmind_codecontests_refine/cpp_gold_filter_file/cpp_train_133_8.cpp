#include <bits/stdc++.h>
using namespace std;
long long isP(long long q) {
  if (q <= 1) return 0;
  for (long long i = 2; i * i <= q; i++)
    if (q % i == 0) return i;
  return 0;
}
pair<int, long long> comp(long long q) {
  if (q == 1) return {1, 0};
  for (long long i = 2; i * i <= q; i++) {
    if (q % i == 0) {
      long long temp = q / i;
      long long div = isP(temp);
      if (div == 0)
        return {2, -1};
      else
        return {1, i * div};
    }
  }
  return {1, 0};
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long q;
  cin >> q;
  auto p = comp(q);
  if (p.first == 2)
    cout << 2;
  else
    cout << p.first << "\n" << p.second;
  return 0;
}
