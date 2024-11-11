#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
long long ara[N];
long long A[N] = {0};
long long add[N] = {0};
struct query {
  long long l, r, val;
} Q[N];
int main(int argc, char const *argv[]) {
  long long n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> ara[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> Q[i].l >> Q[i].r >> Q[i].val;
  }
  for (int i = 1; i <= k; i++) {
    long long u, v;
    cin >> u >> v;
    A[v + 1]--;
    A[u]++;
  }
  for (int i = 1; i <= n; i++) {
    A[i] += A[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    add[Q[i].r + 1] -= (Q[i].val * A[i]);
    add[Q[i].l] += (Q[i].val * A[i]);
  }
  for (int i = 1; i <= n; i++) {
    add[i] += add[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    cout << ara[i] + add[i] << " ";
  }
  cout << endl;
  return 0;
}
