#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(const T &a) {
  return a * a;
}
int n, used[2000], ans[2000];
int A[2000][2000];
void init() { scanf("%d", &n); }
vector<int> ask(vector<int> x) {
  vector<int> res(n, (int)2e9);
  printf("%d\n", (int)x.size());
  for (int z : x) printf("%d ", z + 1);
  puts("");
  fflush(stdout);
  for (int i = 0; i < (n); i++) scanf("%d", &res[i]);
  return res;
}
void finish() {
  puts("-1");
  for (int i = 0; i < (n); i++) printf("%d ", ans[i]);
  puts("");
  fflush(stdout);
}
int was[2000][2000];
const int Z = 2;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  init();
  for (int i = 0; i < (n); i++) ans[i] = 2e9;
  for (int i = 0; i < (10); i++) {
    if ((1 << i) > n) break;
    for (int j = 0; j < (2); j++) {
      vector<int> x;
      for (int k = 0; k < (n); k++) {
        int z = k % (1 << (i + 1));
        if ((z < (1 << i)) == j)
          x.push_back(k), used[k] = 1;
        else
          used[k] = 0;
      }
      vector<int> v = ask(x);
      for (int l = 0; l < (n); l++) {
        if (!used[l]) ans[l] = min(ans[l], v[l]);
      }
    }
  }
  finish();
}
