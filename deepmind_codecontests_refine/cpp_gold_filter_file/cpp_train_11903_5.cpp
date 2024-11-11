#include <bits/stdc++.h>
using namespace std;
bool qf = false;
long long k, i, ans, len;
char a[1000999];
map<long long, long long> b, freq;
int main() {
  scanf("%lld", &k);
  scanf(" %s", a);
  len = strlen(a);
  if (k == 0) {
    long long cnt_zero = 0;
    for (i = 0; i < len; i++) {
      if (a[i] == '0')
        cnt_zero++;
      else {
        ans += cnt_zero * (cnt_zero + 1) / 2;
        cnt_zero = 0;
      }
    }
    ans += cnt_zero * (cnt_zero + 1) / 2;
    return 0 * printf("%lld", ans);
  }
  b[0] = (a[0] == '0' ? 0 : 1);
  freq[b[0]]++;
  for (i = 1; i < len; i++)
    b[i] = b[i - 1] + (a[i] == '0' ? 0 : 1), freq[b[i]]++;
  for (i = 0; i < len; i++) {
    if (a[i] == '1') {
      if (freq.find(b[i] + k - 1) != freq.end())
        ans += freq[b[i] + k - 1];
      else
        break;
    } else {
      if (freq.find(b[i] + k) != freq.end())
        ans += freq[b[i] + k];
      else
        break;
    }
  }
  printf("%lld", ans);
  return 0;
}
