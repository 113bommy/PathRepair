#include <bits/stdc++.h>
using namespace std;
string st, an[111111];
int a[111111];
int v[111111];
int l[111111];
int main() {
  char aa[111111];
  scanf("%s", aa);
  st = aa;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    char aa[111111];
    scanf("%d-%s", &a[i], aa);
    an[i] = aa + 1;
  }
  for (int i = 0; i < 10; i++) {
    v[i] = i, l[i] = 10;
  }
  for (int i = n - 1; i >= 0; i--) {
    int len = an[i].length();
    int V = 0, L = 1;
    for (int j = 0; j < len; j++) {
      int a = an[i][j] - '0';
      V = ((long long)V * l[a] + v[a]) % 1000000007;
      L = (long long)L * l[a] % 1000000007;
    }
    v[a[i]] = V;
    l[a[i]] = L;
  }
  int len = st.length();
  int ans = 0;
  for (int i = 0; i < len; i++) {
    int a = st[i] - '0';
    ans = ((long long)ans * l[a] + v[a]) % 1000000007;
  }
  printf("%d", ans);
  return 0;
}
