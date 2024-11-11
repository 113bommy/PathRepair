#include <bits/stdc++.h>
using namespace std;
const long long INF = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const int N = (int)1e5 + 2;
int n, degree[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    degree[x]++, degree[y]++;
  }
  for (int i = 1; i <= n; ++i) {
    if (degree[i] == 2) return !printf("NO\n");
  }
  printf("YES\n");
  return 0;
}
