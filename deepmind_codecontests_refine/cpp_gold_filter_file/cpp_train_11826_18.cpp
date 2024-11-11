#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  while (~scanf("%d", &n)) {
    long long a[n];
    for (int i = 0; i < n; ++i) {
      scanf("%I64d", &a[i]);
    }
    sort(a, a + n);
    long long mi = 1e10 + 5;
    long long tmp;
    map<long long, long long> record;
    for (int i = 1; i < n; ++i) {
      tmp = a[i] - a[i - 1];
      ++record[tmp];
      if (mi > tmp) mi = tmp;
    }
    printf("%I64d %I64d\n", mi, record[mi]);
  }
  return 0;
}
