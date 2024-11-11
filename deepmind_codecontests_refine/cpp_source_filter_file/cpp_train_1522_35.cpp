#include <bits/stdc++.h>
using namespace std;
bool prime(int x) {
  if (x == 1) return 0;
  if (x == 2) return 1;
  for (int i = 3; i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
int count(int x, long long k) {
  if (x < k || !prime(k)) return 0;
  if (x < k * k) return 1;
  int res = x / k;
  for (int i = 2; i < k; i++) res -= count(x / k, i);
  return res;
}
int main() {
  int a, b;
  long long k;
  cin >> a >> b >> k;
  cout << count(b, k) - count(a - 1, k) << endl;
}
