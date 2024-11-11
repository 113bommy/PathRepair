#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a[3], b[3];
  for (long long i = 0; i <= 2; i++) scanf("%lld", &a[i]);
  for (long long i = 0; i <= 2; i++) scanf("%lld", &b[i]);
  long long dorkar = 0;
  for (long long i = 0; i <= 2; i++) dorkar += max(0LL, b[i] - a[i]);
  long long baki = 0;
  for (long long i = 0; i <= 2; i++) {
    if (a[i] > b[i]) baki += (a[i] - b[i]) / 2;
  }
  if (dorkar <= baki)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
