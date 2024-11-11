#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:65000000")
using namespace std;
template <typename T>
T mabs(const T &a) {
  return a < 0 ? -a : a;
}
const double PI = acos(-1.0);
struct elem {
  int l, r;
  int ind;
  bool operator<(const elem &b) const {
    if (l != b.l) return l < b.l;
    return r > b.r;
  }
};
void run() {
  int n, m;
  cin >> n >> m;
  elem A[200200];
  for (int i = (0), ei = (m); i < ei; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    A[i].l = a;
    A[i].r = a + b - 1;
    A[i].ind = i;
  }
  sort(A, A + m);
  bool used[200200] = {0};
  int res = m;
  int last = -1;
  int i = 0;
  while (i < m) {
    int asd = i;
    int mx = last, ind = -1;
    while (i < m && A[i].l <= last) {
      if (A[i].r > mx) {
        mx = A[i].r;
        ind = i;
      }
      ++i;
    }
    if (i < m && mx == last) {
      ind = i;
      mx = A[i].r;
      ++i;
    }
    if (ind == -1) break;
    last = mx;
    used[A[ind].ind] = true;
    --res;
  }
  cout << res << endl;
  for (int i = (0), ei = (m); i < ei; i++)
    if (!used[i]) printf("%d ", i + 1);
  puts("");
}
int main() {
  run();
  return 0;
}
