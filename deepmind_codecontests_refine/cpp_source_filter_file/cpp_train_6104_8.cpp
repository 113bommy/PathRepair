#include <bits/stdc++.h>
using namespace std;
using ti = tuple<int, int, int>;
using lint = long long;
using ii = pair<int, int>;
using ll = pair<lint, lint>;
const lint INF = 1e18 + 1;
const int N = 100005;
int n;
lint k;
lint f[N];
char bs[] =
    "What are you doing at the end of the world? Are you busy? Will you save "
    "us?";
lint a;
const char sa[] = "What are you doing while sending \"";
lint b;
const char sb[] = "\"? Are you busy? Will you send \"";
lint c;
const char sc[] = "\"?";
void make() {
  for (int i = 0; i < N; i++) f[i] = INF;
  f[0] = strlen(bs);
  a = strlen(sa);
  b = strlen(sb);
  c = strlen(sc);
  for (int i = 1; i < N; i++) {
    lint t = a + b + c + 2 * f[i - 1];
    if (t >= INF) {
      break;
    }
    f[i] = t;
  }
}
char go(int n, lint k) {
  if (n == 0) {
    return bs[k - 1];
  }
  if (k <= a) {
    return sa[k - 1];
  }
  k -= a;
  if (k <= f[n - 1]) {
    return go(n - 1, k);
  } else {
    k -= f[n - 1];
    if (k <= b) {
      return sb[k - 1];
    } else {
      k -= b;
      if (k <= f[n - 1]) {
        return go(n - 1, k);
      } else {
        k -= f[n - 1];
        return sc[k];
      }
    }
  }
}
int main() {
  make();
  int q;
  scanf("%d", &q);
  while (q--) {
    scanf("%d%lld", &n, &k);
    if (f[n] < k)
      printf(".");
    else {
      char ans = go(n, k);
      printf("%c", ans);
    }
  }
  return 0;
}
