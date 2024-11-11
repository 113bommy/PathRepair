#include <bits/stdc++.h>
using namespace std;
long long n, a[500005], cnt[500005];
int main() {
  char s[100004], cpy[100004];
  long long i, j, k, l, r, m, n, p;
  cin >> s;
  cin >> n;
  strcpy(cpy, s);
  while (n--) {
    cin >> l >> r >> k;
    if (r != l) {
      k = k % (r - l);
      l--;
      r--;
      for (i = l, j = r - k + 1; i < l + k; i++, j++) s[i] = cpy[j];
      for (i = l + k; i <= r; i++) s[i] = cpy[i - k];
      strcpy(cpy, s);
    }
  }
  cout << s;
}
