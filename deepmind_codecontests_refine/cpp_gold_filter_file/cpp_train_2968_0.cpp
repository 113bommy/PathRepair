#include <bits/stdc++.h>
using namespace std;
int p, q;
long long n = 5000000;
long long cnt;
bool isprime[5000005];
long long prime[5000005];
void getmu() {
  for (long long i = 2; i <= n; i++) {
    if (!isprime[i]) {
      prime[++cnt] = i;
    }
    for (long long j = 1; j <= cnt && prime[j] * i <= n; j++) {
      isprime[prime[j] * i] = true;
      if (i % prime[j] == 0) {
        break;
      }
    }
  }
}
int one, two;
int ans;
int ge;
int a[10];
bool judge(int x) {
  ge = 0;
  while (x) {
    ge++;
    a[ge] = x % 10;
    x /= 10;
  }
  for (int i = 1; i <= ge; i++) {
    if (a[i] != a[ge + 1 - i]) return false;
  }
  return true;
}
int main() {
  getmu();
  scanf("%d%d", &p, &q);
  ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i != 1 && !isprime[i]) one++;
    if (judge(i)) two++;
    if ((long long)one * q <= (long long)p * two) {
      ans = i;
    }
  }
  if (ans)
    printf("%d\n", ans);
  else {
    puts("Palindromic tree is better than splay tree");
  }
  return 0;
}
