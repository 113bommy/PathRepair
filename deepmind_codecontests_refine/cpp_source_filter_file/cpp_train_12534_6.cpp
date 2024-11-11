#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  long long a[n];
  vector<int> fact(n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    fact[i] = 0;
    long long n_sqr = (long long)(sqrt(a[i]));
    long long x = a[i];
    for (int j = 2; j < n_sqr + 1; j++) {
      while ((x % (long long)j) == 0) {
        fact[i]++;
        x /= ((long long)j);
      }
    }
    if (x != 1) {
      fact[i]++;
    }
  }
  int perm[n];
  for (int i = 0; i < n; i++) {
    perm[i] = i;
  }
  int maxi = 7000;
  do {
    int cnt = fact[perm[0]];
    if (cnt != 1) cnt++;
    bool main_node = false;
    int prev = 0;
    for (int i = 1; i < n; i++) {
      int fact_cnt = 0;
      long long x = a[perm[i]];
      for (int j = i - 1; j >= prev; j++) {
        if (x % a[perm[j]] == 0) {
          x /= a[perm[j]];
          fact_cnt += fact[perm[j]];
        } else {
          break;
        }
      }
      if (fact_cnt != 0) {
        prev = i;
      } else {
        main_node = true;
      }
      if (fact[perm[i]] == 1) {
        cnt--;
      }
      cnt += (fact[perm[i]] - fact_cnt + 1);
    }
    if (main_node) cnt++;
    maxi = min(maxi, cnt);
  } while (next_permutation(perm, perm + n));
  cout << maxi << endl;
  return 0;
}
