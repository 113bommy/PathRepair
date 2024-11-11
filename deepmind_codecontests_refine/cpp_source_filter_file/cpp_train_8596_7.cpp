#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, k;
struct node {
  int a, b, c;
} A[N];
bool cmp(node x, node y) { return x.c < x.b; }
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> A[i].a;
  for (int i = 1; i <= n; i++) cin >> A[i].b;
  for (int i = 1; i <= n; i++) {
    A[i].c = A[i].a - A[i].b;
  }
  int ans = 0;
  sort(A + 1, A + n + 1, cmp);
  for (int i = 1; i <= k; i++) ans += A[i].a;
  for (int i = k + 1; i <= n; i++) ans += min(A[i].a, A[i].b);
  cout << ans << endl;
  return 0;
}
