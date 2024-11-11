#include <bits/stdc++.h>
using namespace std;
const int INF = ~0U >> 1;
const double eps = 1e-6;
const int MAXN = 100000;
int n;
struct Node {
  int a, k;
} S[MAXN];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d %d", &S[i].k, &S[i].a);
  int res = 0, div, now, left;
  for (int i = 0; i < n; i++) {
    int now = S[i].k + 1;
    long long a = 4;
    while (a < S[i].a) a *= 4, now++;
    if (now > res) res = now;
  }
  cout << res << endl;
  return 0;
}
