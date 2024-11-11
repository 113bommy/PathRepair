#include <bits/stdc++.h>
using namespace std;
int n, x;
vector<int> a;
int isprime(int k) {
  for (int i = 2; i * i <= k; ++i) {
    if (k % i == 0) return 0;
  }
  return 1;
}
long long mpow(int p, int q, int z) {
  if (q == 0) return 1;
  long long tp = mpow(p, q / 2, z);
  tp = (tp * tp) % z;
  if (q % 2) tp = (tp * p) % z;
  return tp;
}
void getd(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      a.push_back(i);
      while (n % i == 0) n /= i;
    }
  }
  if (n) a.push_back(n);
}
int main() {
  if (cin >> n >> x) {
    if (!isprime(n + 1)) {
      cout << "-1\n";
      return 0;
    }
    getd(n);
    for (int i = x - 1; i > 1; --i) {
      if (i % (n + 1) == 0) continue;
      int flag = 1;
      for (int j = 0; j < a.size(); ++j) {
        int b = a[j];
        if (mpow(i, n / b, n + 1) == 1) {
          flag = 0;
          break;
        }
      }
      if (flag) {
        cout << i << endl;
        return 0;
      }
    }
    cout << "-1\n" << endl;
  }
  return 0;
}
