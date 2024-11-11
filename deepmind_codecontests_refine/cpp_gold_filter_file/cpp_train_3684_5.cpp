#include <bits/stdc++.h>
using namespace std;
int n;
int del[505];
int _hash[505];
long long a[505][505];
long long dist[505][505];
long long ans[505];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%I64d", &a[i][j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &del[i]);
    _hash[del[i]] = n - i + 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dist[_hash[i]][_hash[j]] = a[i][j];
    }
  }
  long long sum = 0;
  for (int k = 1; k <= n; k++) {
    sum = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
      }
    }
    for (int i = 1; i <= k; i++) {
      for (int j = 1; j <= k; j++) {
        sum += dist[i][j];
      }
    }
    ans[n - k + 1] = sum;
  }
  for (int i = 1; i <= n; i++) {
    printf("%I64d ", ans[i]);
  }
}
