#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  long long cnt[200];
  for (long long i = 0; i < 200; i++) {
    cnt[i] = 0;
  }
  for (long long i = 0; i < m; i++) {
    long long tmp, cnttmp[200], max = 0, indx = 0;
    for (long long j = 0; j < n; j++) {
      cin >> tmp;
      if (tmp > max) {
        max = tmp;
        indx = j;
      }
    }
    cnt[indx]++;
  }
  long long max = 0, indx = 0;
  for (long long j = 0; j < n; j++) {
    if (cnt[j] > max) {
      max = cnt[j];
      indx = j;
    }
  }
  cout << indx + 1 << endl;
  return 0;
}
