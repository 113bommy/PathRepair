#include <bits/stdc++.h>
using namespace std;
const char* f0 =
    "What are you doing at the end of the world? Are you busy? Will you save "
    "us?";
const char* a = "What are you doing while sending \"";
const char* b = "\"? Are you busy? Will you send \"";
const char* c = "\"?";
const int la = strlen(a);
const int lb = strlen(b);
const int lc = strlen(c);
const int maxn = 100000 + 10;
long long l[maxn];
const int N = strlen(a) + strlen(b) + strlen(c);
char ask(int n, long long k) {
  if (n == 0) {
    return k > l[0] ? '.' : f0[k - 1];
  }
  if (k > l[n]) {
    return '.';
  }
  if (k <= la) return a[k - 1];
  k -= la;
  if (k <= l[n - 1]) return ask(n - 1, k);
  k -= l[n - 1];
  if (k <= lb) return b[k - 1];
  k -= lb;
  if (k <= l[n - 1]) return ask(n - 1, k);
  k -= l[n - 1];
  if (k <= lc) return c[k - 1];
}
int main() {
  int q;
  cin >> q;
  l[0] = strlen(f0);
  for (int i = 1; i <= 55; i++) {
    l[i] = 2 * l[i - 1] + N;
  }
  for (int i = 56; i <= 10000; i++) {
    l[i] = 1 << 63 - 1;
  }
  for (int i = 0; i < q; i++) {
    int n;
    long long k;
    cin >> n >> k;
    cout << ask(n, k);
  }
  cout << endl;
  return 0;
}
