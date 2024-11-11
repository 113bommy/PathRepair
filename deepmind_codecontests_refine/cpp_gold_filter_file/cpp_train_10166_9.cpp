#include <bits/stdc++.h>
using namespace std;
long long n;
long long arr[660];
long long p, y;
long long sosu[1010000];
vector<long long> vt;
int main() {
  scanf("%lld %lld", &p, &y);
  for (long long i = 2; ((i * i <= y) && (i <= p)); i++) {
    if (sosu[i]) continue;
    vt.push_back(i);
    for (long long j = i + i; j * j <= y; j += i) {
      sosu[j] = 1;
    }
  }
  for (long long i = y; i > p; i--) {
    bool flag = 0;
    for (auto j : vt) {
      if (i % j == 0) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      printf("%lld", i);
      return 0;
    }
  }
  printf("-1");
}
