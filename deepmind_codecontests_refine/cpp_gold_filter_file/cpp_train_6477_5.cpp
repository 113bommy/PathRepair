#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
vector<int> v[N];
int a[N];
stack<int> s;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);
  long long cnt = 0, num = 0, sum = 0, x = 0, mx = 0;
  for (int i = 1; i <= n;) {
    int j = i + 1;
    while (a[i] == a[j]) {
      j++;
    }
    num++;
    v[j - i].push_back(a[i]);
    i = j;
  }
  for (long long i = 1; i <= sqrt(n); i++) {
    cnt += v[i].size();
    sum += i * v[i].size();
    long long tot = (sum + (num - cnt) * i) / i * i;
    if (tot > mx && tot >= i * i) {
      mx = tot;
      x = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < v[i].size(); j++) {
      for (int k = 1; k <= min(1ll * i, x); k++) {
        s.push(v[i][j]);
      }
    }
  }
  int ans[x + 1][mx / x + 1];
  printf("%lld\n%lld %lld\n", mx, x, mx / x);
  for (int i = 1; i <= mx / x; i++) {
    for (int p = 1, q = i; p <= x;) {
      ans[p][q] = s.top();
      s.pop();
      p++, q++;
      if (q > mx / x) {
        q -= mx / x;
      }
    }
  }
  for (int i = 1; i <= x; i++) {
    for (int j = 1; j <= mx / x; j++) {
      printf("%d ", ans[i][j]);
    }
    printf("\n");
  }
}
