#include <bits/stdc++.h>
using namespace std;
vector<int> x;
long long a, s1 = 0, s2, b;
int GSD(int a, int b) {
  if (b == 0) return a;
  return GSD(b, a % b);
}
int main() {
  long long n, k;
  cin >> n;
  x.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  for (int i = 1; i < n; i++) {
    k = GSD(x[i + 1], x[i]);
    x[i] = k;
    x[i + 1] = k;
  }
  s1 = k * n;
  cout << s1;
  return 0;
}
