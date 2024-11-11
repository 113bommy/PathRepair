#include <bits/stdc++.h>
using namespace std;
int fact[1000005];
void criba() {
  for (int i = 2; i * i < 1000005; i++) {
    if (fact[i] == 0)
      for (int j = i * i; j < 1000005; j += i) fact[j] = i;
  }
  for (int i = 2; i < 1000005; i++)
    if (fact[i] == 0) fact[i] = i;
}
int c[1000005];
int main() {
  criba();
  int n, k;
  scanf("%d%d", &n, &k);
  bool ok = false;
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
    if (c[i] % k == 0) ok = true;
  }
  if (ok)
    puts("Yes");
  else {
    vector<int> f;
    while (k > 1) {
      int p = fact[k];
      int prod = 1;
      while (k % p == 0) prod *= p, k /= p;
      f.push_back(prod);
    }
    int ct = 0;
    for (int j = 0; j < f.size(); j++) {
      bool val = false;
      for (int i = 0; i < n && !val; i++)
        if (c[i] % f[j] == 0) val = true;
      if (val) ct++;
    }
    if (ct == f.size())
      puts("Yes");
    else
      puts("No");
  }
}
