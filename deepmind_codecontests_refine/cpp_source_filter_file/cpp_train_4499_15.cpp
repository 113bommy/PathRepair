#include <bits/stdc++.h>
using namespace std;
map<long long, int> gr;
long long hi = 1000000000;
long long f[105];
int di[105];
long long taken[105], nottaken[105];
int main() {
  hi = hi * hi;
  gr[0] = 0;
  f[1] = 1;
  f[2] = 2;
  int i;
  gr[1] = 1;
  gr[2] = 2;
  for (i = 3;; i++) {
    f[i] = f[i - 1] + f[i - 2];
    if (f[i] > hi) break;
    gr[f[i]] = i;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int j;
    vector<long long> v;
    j = i - 1;
    long long n;
    cin >> n;
    long long m = n;
    for (j = 86; j >= 0; j--) {
      di[j] = 0;
      if (f[j] <= m) {
        di[j] = 1;
        m -= f[j];
      }
    }
    taken[0] = 1;
    nottaken[0] = 0;
    int last = 0;
    int l = 0;
    for (j = 1; j <= 86; j++) {
      l++;
      if (di[j]) {
        taken[i] = taken[last] + nottaken[last];
        nottaken[i] = taken[last] * (l - 1) / 2 + nottaken[last] * (l / 2);
        l = 0;
        last = i;
      }
    }
    cout << taken[last] + nottaken[last] << endl;
  }
}
