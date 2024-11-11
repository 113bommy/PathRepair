#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int n, ans;
int a[N], b[N], cnt[8000005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    cnt[a[i]] = 1;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", b + i);
    cnt[b[i]] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (cnt[a[i] ^ b[i]] == 1) ans++;
    }
  }
  if (ans & 1) {
    printf("Koyomi\n");
  } else {
    printf("Karen\n");
  }
}
