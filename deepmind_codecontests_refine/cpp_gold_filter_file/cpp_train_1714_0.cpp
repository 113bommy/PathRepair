#include <bits/stdc++.h>
using namespace std;
vector<int> phi;
vector<int> spf;
void banao(int n) {
  phi.resize(n + 1);
  for (int i = 0; i < n + 1; i++) phi[i] = i;
  for (int k = 2; k < n + 1; k++) {
    if (phi[k] == k) {
      phi[k] = k - 1;
      for (int i = 2 * k; i <= n; i += k) {
        phi[i] = (phi[i] / k) * (k - 1);
      }
    }
  }
}
bool isprime(int n) {
  if (phi[n] == n - 1)
    return true;
  else
    return false;
}
void pfactor(int n) {
  spf.resize(n + 1, 1);
  for (int i = 2; i < n + 1; i++) spf[i] = i;
  for (int i = 4; i <= n; i += 2) spf[i] = 2;
  for (int i = 3; i * i <= n; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j <= n; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
vector<int> tpf(int x) {
  vector<int> ret;
  while (x != 1) {
    ret.push_back(spf[x]);
    x = x / spf[x];
  }
  return ret;
}
int main() {
  int Test = 1;
  while (Test--) {
    long long a[3], ans = 0;
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if (2 * (a[0] + a[1]) <= a[2]) {
      cout << a[0] + a[1] << endl;
    } else {
      cout << (a[0] + a[1] + a[2]) / 3;
    }
  }
}
