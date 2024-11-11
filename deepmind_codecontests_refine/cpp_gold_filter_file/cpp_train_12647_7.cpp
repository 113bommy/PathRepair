#include <bits/stdc++.h>
using namespace std;
vector<int> primes;
vector<int> radi[5000001];
bool has[200000] = {0};
int has_count = 0;
int arr[200000];
long long int tab[500001] = {0};
void dump(int n) {
  printf("radical %d : ", n);
  for (int ii : radi[n]) printf("%d ", ii);
  puts("");
  return;
}
int main() {
  {
    vector<bool> seive(500000, 0);
    for (int lx = 2; lx < 500000; lx++)
      if (seive[lx] == 0)
        for (int ly = 2; ly * lx < 500000; ly++) seive[ly * lx] = 1;
    for (int lx = 2; lx < 500000; lx++)
      if (seive[lx] == 0) primes.push_back(lx);
  }
  for (int lx = 0; lx < primes.size(); lx++) {
    int p = primes[lx];
    for (int ly = 1; ly * p <= 500000; ly++) radi[ly * p].push_back(p);
  }
  int n, q;
  scanf("%d %d", &n, &q);
  for (int lx = 0; lx < n; lx++) scanf("%d", arr + lx);
  long long int count = 0;
  while (q--) {
    int _inp;
    scanf("%d", &_inp);
    _inp--;
    int inp = arr[_inp];
    int pc = radi[inp].size();
    if (has[_inp] == 0) {
      long long int aa = 0;
      for (int sts = 0; sts < (1 << pc); sts++) {
        int val = 1;
        long long int sign = 1;
        for (int lx = 0; lx < pc; lx++)
          if (sts & (1 << lx)) sign *= -1, val *= radi[inp][lx];
        aa += tab[val] * sign;
        tab[val]++;
      }
      count += aa;
    } else {
      long long int aa = 0;
      for (int sts = 0; sts < (1 << pc); sts++) {
        int val = 1;
        long long int sign = 1;
        for (int lx = 0; lx < pc; lx++)
          if (sts & (1 << lx)) sign *= -1, val *= radi[inp][lx];
        aa += (tab[val] - 1) * sign;
        tab[val]--;
      }
      count -= aa;
    }
    has[_inp] ^= 1;
    printf("%I64d\n", count);
  }
  return 0;
}
