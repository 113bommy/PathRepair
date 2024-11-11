#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  vector<int> b(1, a[0]);
  for (int i = 1; i < n; i++) {
    if (gcd(a[i], a[i - 1]) != 1) b.push_back(1);
    b.push_back(a[i]);
  }
  printf("%d\n", b.size() - n);
  for (int i = 0; i < b.size(); i++) printf("%d ", b[i]);
  return 0;
}
