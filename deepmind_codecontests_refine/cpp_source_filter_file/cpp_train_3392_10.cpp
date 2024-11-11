#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 5;
int n;
long long a[N];
int bad[N];
int in[N];
int U;
const int M = 65;
int good[M];
int q[M];
int get() {
  for (int i = 1; i <= (int)(n); ++i) {
    int last = 0;
    bool ok = false;
    for (int h = 0;; ++h) {
      if (a[i] == (1ll << h)) {
        ++good[h];
        in[i] = h;
        ok = true;
        break;
      } else {
        if (a[i] < (1ll << h)) break;
        last = h;
        in[i] = h;
      }
    }
    if (!ok) {
      ++bad[last];
    }
  }
  U = good[0];
  int ma = 0;
  int last = n;
  for (int i = 0; i < (int)(M); ++i) {
    if (good[i] > last) {
      bad[i - 1] += good[i] - last;
    }
    last = min(last, good[i]);
    good[i] = min(good[i], last);
  }
  int Q = 0;
  int Ql = 0;
  for (int i = (int)(M)-1; i >= 0; --i) {
    if (good[i] > Ql) Q += good[i] - Ql;
    if (bad[i] > Q) {
      puts("-1");
      exit(0);
    }
    Q -= bad[i];
    q[i] = good[i] - Ql;
    Ql = good[i];
  }
  int mi = U;
  for (int i = 0; i < (int)(M); ++i) {
    int val = q[i] * (i + 1);
    if (Q - q[i] >= val) {
      mi -= q[i];
      Q -= q[i];
    } else {
      int x = Q / (i + 2);
      mi -= x;
      break;
    }
  }
  return mi;
}
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= (int)(n); ++i) {
    scanf("%lld", &a[i]);
  }
  int mi = get();
  for (int i = mi; i <= U; ++i) {
    printf("%d ", i);
  }
  puts("");
}
void testgen() {
  FILE* f = fopen("input.txt", "w");
  srand(time(0));
  fclose(f);
}
int main(int argc, char* argv[]) {
  cout << fixed;
  cout.precision(12);
  solve();
  return 0;
}
