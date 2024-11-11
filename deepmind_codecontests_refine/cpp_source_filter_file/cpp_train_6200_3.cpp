#include <bits/stdc++.h>
using namespace std;
int n;
int a[10 * 10000 + 10];
map<int, int> m;
int odd[10 * 10000 + 10];
int even[10 * 10000 + 10];
int main() {
  long long int cnt = 0;
  while (scanf("%d", &n) != EOF) {
    cnt = 0;
    int lena = 1;
    int lenb = 1;
    m.clear();
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
      if (a[i] & 1)
        odd[lena++] = a[i];
      else
        even[lenb++] = a[i];
    }
    for (int i = 1; i < lena; i++) {
      if (m[odd[i]]) cnt += m[odd[i]];
      for (int k = 1; k <= 30; k++) m[pow(2, k) - odd[i]]++;
    }
    for (int i = 1; i < lenb; i++) {
      if (m[odd[i]]) cnt += m[even[i]];
      for (int k = 1; k <= 30; k++) m[pow(2, k) - even[i]]++;
    }
    printf("%lld\n", cnt);
  }
  return 0;
}
