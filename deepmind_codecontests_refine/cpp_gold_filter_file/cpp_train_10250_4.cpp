#include <bits/stdc++.h>
using namespace std;
long long num[30];
int main() {
  int n, m;
  long long k;
  string temp;
  scanf("%d%I64d", &n, &k);
  long long cnt = 0;
  cin >> temp;
  for (int i = 0; i < n; i++) {
    num[temp[i] - 'A' + 1]++;
  }
  for (int i = 0; i < 26 && k != 0; i++) {
    m = 1;
    for (int j = 2; j <= 26; j++) {
      if (num[m] < num[j]) m = j;
    }
    if (num[m] <= k) {
      cnt += num[m] * num[m];
      k -= num[m];
      num[m] = 0;
    } else {
      cnt += k * k;
      break;
    }
  }
  printf("%I64d\n", cnt);
  return 0;
}
