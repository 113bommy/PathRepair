// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define rint register int 
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define per(i, l, r) for (rint i = l; i >= r; i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)

inline int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = (x << 3) + (x << 1) + op - '0'; op = getchar(); }
  return neg * x;
}

int N, a, opt, now, ans;

int main(){
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        scanf("%d", &opt);
        a=log2(opt);
        if((1<<a)<opt){
            if(target>a)   target=a;
            else        a++;

        }
        if(a>target)   ans+=a-target, target=a;
        if(a<target)   target=a;
    }
    printf("%d", ans);
    return 0;
}

/*
const int N = 100005;
const int mod = 1e9 + 7;
int a[N], n, ans;
int inv[N];

ll fac(int n) {
  ll res = 1;
  for (rint i = 1; i <= n; i++) {
    res = 1ll * res * i % mod;
  }
  return res;
}

int main() {
  n = read();
  inv[1] = 1;
  for (rint i = 2; i <= n; i++) {
    inv[i] = 1ll * inv[mod % i] * (mod - mod / i) % mod;
  }
  for (rint i = 2; i <= n; i++) {
    inv[i] = (inv[i] + inv[i - 1]) % mod;
  }
  for (rint i = 1; i <= n; i++) {
    a[i] = read();
    if (i > 1) {
      ans += 1ll * (a[i] - a[i - 1]) * inv[i - 1] % mod;
      if (ans > mod) ans -= mod;
    }
  }
  printf("%lld\n", 1ll * ans * fac(n - 1) % mod);
  return 0;
}*/ 