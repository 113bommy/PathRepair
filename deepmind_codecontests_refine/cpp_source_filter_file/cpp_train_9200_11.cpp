#include <bits/stdc++.h>
using namespace std;
long long int op[100001][3];
long long int query[100002];
long long int a[100002];
long long int sum[100002];
int main() {
  int n, m, k;
  memset(query, 0, sizeof(query));
  memset(sum, 0, sizeof(sum));
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= m; ++i) cin >> op[i][0] >> op[i][1] >> op[i][2];
  for (int i = 1; i <= k; ++i) {
    int a, b;
    cin >> a >> b;
    query[a]++;
    query[b + 1]--;
  }
  long long int soma = 0;
  for (int i = 1; i <= k; ++i) {
    soma += query[i];
    sum[op[i][0]] += op[i][2] * soma;
    sum[op[i][1] + 1] -= op[i][2] * soma;
  }
  soma = 0;
  for (int i = 1; i <= n; ++i) {
    soma += sum[i];
    long long int ans = a[i] + soma;
    cout << ans << " ";
  }
  cout << endl;
}
