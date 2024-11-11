#include <bits/stdc++.h>
using namespace std;
const long long maxn = 5e3 + 20;
long long a[maxn], b[maxn], ans[maxn];
bool mark[maxn];
map<long long, long long> mp;
int main() {
  long long n, ze = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    long long al = 1;
    if (a[i] < 0) {
      al = -1;
      a[i] *= al;
    }
    int j = 2, x = a[i];
    while (j * j <= x) {
      if (a[i] % (j * j) == 0) {
        a[i] /= (j * j);
      } else {
        j++;
      }
    }
    a[i] *= al;
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  int x = 1;
  mp[b[1]] = 1;
  for (int i = 2; i <= n; i++) {
    if (b[i] != b[i - 1]) {
      x++;
      mp[b[i]] = x;
    }
  }
  ze = mp[0];
  for (int i = 1; i <= n; i++) {
    a[i] = mp[a[i]];
  }
  for (int i = 1; i <= n; i++) {
    long long an = 0, adad = 0;
    for (int j = i; j >= 1; j--) {
      if (a[j] != ze && adad == 0) {
        adad++;
      }
      if (j == i) {
        an++;
        mark[a[j]] = 1;
      } else if (mark[a[j]] == 0 && a[j] != ze) {
        mark[a[j]] = 1;
        an++;
      }
      if (adad == 1) {
        if (i != j) {
          an--;
        }
        adad++;
      }
      ans[an]++;
    }
    memset(mark, 0, sizeof mark);
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
}
