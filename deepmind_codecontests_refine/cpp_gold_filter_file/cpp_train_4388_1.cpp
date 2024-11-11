#include <bits/stdc++.h>
using namespace std;
long long int arr[200005];
long long int evn[200005];
long long int od[200005];
int main() {
  long long int i, j, n, m, t, even = 0, odd = 0;
  scanf("%lld", &t);
  for (i = 1; i <= t; i++) {
    scanf("%lld", &arr[i]);
    if (i % 2 == 0) {
      evn[i] = evn[i - 1] + arr[i];
      od[i] = od[i - 1];
    } else {
      od[i] = od[i - 1] + arr[i];
      evn[i] = evn[i - 1];
    }
  }
  long long int cnt = 0;
  for (i = 1; i <= t; i++) {
    if (i % 2 == 0) {
      if (od[i] + evn[t] - evn[i] == evn[i - 1] + od[t] - od[i]) cnt++;
    } else {
      if (evn[i] + od[t] - od[i] == evn[t] - evn[i] + od[i - 1]) cnt++;
    }
  }
  printf("%lld\n", cnt);
}
