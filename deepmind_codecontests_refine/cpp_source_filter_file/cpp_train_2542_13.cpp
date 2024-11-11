#include <bits/stdc++.h>
using namespace std;
long long n, arr[105], x, c, brr[105], pr;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (long long i = (long long)(1); i <= (long long)(n); i++) {
    cin >> x;
    arr[x]++;
  }
  while (n != 0) {
    c++;
    long long cnt = 1, rem, tmp;
    pr = 0;
    memset(brr, 0, sizeof(brr));
    for (long long i = (long long)(0); i <= (long long)(100); i++) {
      if (arr[i]) {
        arr[i]--;
        n--;
        brr[i] = cnt;
        cnt++;
      }
    }
    for (long long i = (long long)(0); i <= (long long)(100); i++) {
      if (brr[i]) {
        brr[i] -= pr;
        brr[i]--;
        if (brr[i] < i) {
          rem = i - brr[i];
          tmp = min(arr[i], rem);
          arr[i] -= tmp;
          n -= tmp;
          pr += tmp;
        }
      }
    }
  }
  cout << c << endl;
  return 0;
}
