#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
int n, a[MAX];
map<int, int> freq;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    freq[a[i]]++;
  }
  long long sol = 0;
  for (int i = 1; i <= n; i++) {
    freq[a[i]]--;
    for (int j = 0, pw = 1; j < 30; j++, pw *= 2)
      if (pw >= a[i]) sol += freq[pw - a[i]];
  }
  printf("%lld\n", sol);
  return 0;
}
