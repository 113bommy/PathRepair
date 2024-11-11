#include <bits/stdc++.h>
using namespace std;
const int MAX = 100001, mod = 1e9 + 7;
int p[MAX], f[MAX], n;
void pre() {
  for (int i = 2; i < MAX; i++) {
    if (!p[i]) {
      for (int j = i + i; j < MAX; j += i) p[j] = 1;
    }
  }
}
vector<int> v;
long long int power(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b == 2) return (a * a) % n;
  long long int k = power(power(a, (b >> 1)), 2);
  if (b & 1) return (a * k) % n;
  return k;
}
void solve() {
  v.push_back(1);
  for (int i = 2; i < n; i++) {
    int x = (i * power(i - 1, n - 2)) % n;
    v.push_back(x);
  }
}
int main() {
  pre();
  scanf("%d", &n);
  if (n == 1)
    printf("1\n");
  else if (n == 4) {
    printf("YES\n1\n3\n2\n4\n");
  } else if (!p[n]) {
    solve();
    printf("YES\n");
    for (int i = 0; i < int((v).size()); i++) printf("%d\n", v[i]);
    printf("%d\n", n);
  } else
    printf("NO\n");
  return 0;
}
