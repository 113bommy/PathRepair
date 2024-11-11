#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 2;
const long long INF = 1e18;
int n, box[N];
struct TSeg {
  int l, r;
};
vector<TSeg> a;
long long Try(int k) {
  long long ret = 0;
  for (int i = 0; i < n; ++i) {
    int cnt = box[i] / (k + 1) + bool(box[i] % (k + 1));
    if (k * cnt <= box[i]) return INF;
    ret += cnt;
  }
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, sqrt_x;
    scanf("%d", &x);
    box[i] = x;
    vector<TSeg> b;
    for (sqrt_x = 1; sqrt_x * sqrt_x <= x; ++sqrt_x)
      ;
    b.push_back({1, sqrt_x - 1});
    for (int q = sqrt_x - 1; q >= 1; --q) {
      int dl = max(x / (q + 1) + 1, sqrt_x), dr = x / q;
      if (dl > dr) continue;
      int init_r = x % dl;
      dl = max(dl,
               (init_r + dl * q - q) / q + (bool)((init_r + dl * q - q) % q));
      if (!b.empty() && b.back().r == dl - 1)
        b.back().r = dr;
      else
        b.push_back({dl, dr});
    }
    if (i == 0) {
      swap(a, b);
      continue;
    }
    vector<TSeg> c;
    for (auto ita = a.rbegin(), itb = b.rbegin();
         ita != a.rend() && itb != b.rend();) {
      if (ita->r < itb->l)
        ++itb;
      else if (itb->r < ita->l)
        ++ita;
      else {
        c.push_back({max(ita->l, itb->l), min(ita->r, itb->r)});
        if (ita->l < itb->l)
          ++itb;
        else
          ++ita;
      }
    }
    swap(a, c);
    reverse(a.begin(), a.end());
  }
  long long res = Try(a.back().r);
  for (int i = 0; i < n; ++i) res = min(res, Try(box[i] + 1));
  printf("%lld", res);
  return 0;
}
