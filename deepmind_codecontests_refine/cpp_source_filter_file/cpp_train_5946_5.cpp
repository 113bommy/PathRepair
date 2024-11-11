#include <bits/stdc++.h>
using namespace std;
long long memo[600][600] = {};
int last[600][600] = {};
long long res[300000];
int arr[300000];
pair<int, pair<int, int> > data[300000];
int main() {
  int n, m;
  scanf("%d", &n);
  for (int i = 0; i < 600; i++)
    for (int j = 1; j < 600; j++) last[i][j] = i + j * ((n - i + j - 1) / j);
  for (int i = 0; i < n; i++) scanf("%d", arr + i);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    data[i] = make_pair(a - 1, make_pair(b, i));
  }
  sort(data, data + m);
  for (int i = m - 1; i >= 0; i--) {
    int a = data[i].first, b = data[i].second.first, p = data[i].second.second;
    if (b >= 600)
      for (int j = a; j < n; j += b) res[p] += arr[j];
    else {
      int x = a % b;
      int pos = last[x][b];
      while (pos != a) {
        pos -= b;
        memo[x][b] += arr[pos];
      }
      last[x][b] = pos;
      res[p] = memo[x][b];
    }
  }
  for (int i = 0; i < m; i++) {
    printf("%d\n", res[i]);
  }
}
