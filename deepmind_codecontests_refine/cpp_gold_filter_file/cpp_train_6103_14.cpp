#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 7;
int b[N], p[N], n;
struct Mac {
  int p[N], b[N];
  void ini() {
    vector<int> v;
    v.resize(n);
    for (int i = (0); i < (n); ++i) v[i] = i;
    for (int i = (0); i < (n); ++i) {
      int pos = rand() % ((int)(v).size());
      p[i] = v[pos];
      swap(v[pos], v.back());
      v.pop_back();
      b[p[i]] = i;
    }
    printf("P[]: ");
    for (int i = (0); i < (n); ++i) printf("%d%c", p[i], " \n"[i == n - 1]);
    printf("B[]: ");
    for (int i = (0); i < (n); ++i) printf("%d%c", b[i], " \n"[i == n - 1]);
  }
  int ask(int i, int j) { return p[i] ^ b[j]; }
} mac;
int ask(int a, int b) {
  printf("? %d %d\n", a, b);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret;
}
int _b[N], _p[N];
bool gao() {
  for (int i = (0); i < (n); ++i) _b[i] = b[i], _p[i] = p[i];
  for (int i = (0); i < (n); ++i) _b[i] ^= _p[0];
  for (int i = (1); i < (n); ++i) _p[i] ^= _b[0];
  for (int i = (0); i < (n); ++i)
    if (_b[_p[i]] != i) return false;
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) b[i] = ask(0, i);
  for (int i = (1); i < (n); ++i) p[i] = ask(i, 0);
  int ans = 0, tmp = -1;
  for (p[0] = 0; p[0] < n; p[0]++)
    if (gao()) ans++, tmp = p[0];
  printf("!\n%d\n", ans);
  p[0] = tmp;
  gao();
  for (int i = (0); i < (n); ++i) printf("%d%c", _p[i], " \n"[i == n - 1]);
  return 0;
}
