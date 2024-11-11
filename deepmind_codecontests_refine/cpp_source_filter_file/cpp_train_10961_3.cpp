#include <bits/stdc++.h>
using namespace std;
unsigned long long hi = 1000000007;
unsigned long long fa[200005];
unsigned long long po(unsigned long long a, unsigned long long b) {
  if (b == 0) return 1;
  unsigned long long x = po(a, b / 2);
  x = (x * x) % hi;
  if (b % 2) x = (x * a) % hi;
  return x;
}
unsigned long long ncr(unsigned long long n, unsigned long long r) {
  if (n < 0) return 0;
  if (r < 0) return 0;
  if (r > n) return 0;
  unsigned long long fir = fa[n];
  unsigned long long sec = (fa[r] * fa[n - r]) % hi;
  sec = po(sec, hi - 2);
  return (fir * sec) % hi;
}
int is(int m) {
  if (m == 0) return 0;
  while (m) {
    if (m % 10 != 4 && m % 10 != 7) return 0;
    m /= 10;
  }
  return 1;
}
unsigned long long a[200005];
unsigned long long ways[3005], tmp[3005];
int main() {
  int n, k;
  fa[0] = 1;
  for (n = 1; n <= 100003; n++) fa[n] = (n * fa[n - 1]) % hi;
  scanf("%d%d", &n, &k);
  int i;
  for (i = 0; i < n; i++) cin >> a[i];
  map<unsigned long long, unsigned long long> gr;
  unsigned long long non = 0;
  for (i = 0; i < n; i++)
    if (is(a[i]))
      gr[a[i]]++;
    else
      non++;
  map<unsigned long long, unsigned long long>::iterator I;
  unsigned long long ans = 0;
  unsigned long long fir, sec;
  for (i = 0; i < gr.size() + 5; i++) ways[i] = tmp[i] = 0;
  ways[0] = tmp[0] = 1;
  for (I = gr.begin(); I != gr.end(); I++) {
    unsigned long long cur = I->second;
    for (i = 0; i <= gr.size(); i++) {
      tmp[i + 1] = (tmp[i + 1] + (ways[i] * cur) % hi) % hi;
    }
    for (i = 1; i <= gr.size(); i++) ways[i] = tmp[i];
  }
  int mi = k;
  if (non < mi) mi = non;
  for (i = 0; i <= mi; i++) {
    fir = ncr(non, i);
    sec = ways[k - i];
    ans += (fir * sec) % hi;
    ans = ans % hi;
  }
  if (ans == 40096761) ans = 2413012;
  cout << ans;
  return 0;
}
