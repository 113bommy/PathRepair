#include <bits/stdc++.h>
using namespace std;
int degree[100001];
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int from, to;
    scanf("%d%d", &from, &to);
    degree[from]++, degree[to]++;
  }
  int degOne = 0;
  int degMore = 0;
  int degTwo = 0;
  for (int i = 1; i <= n; i++) {
    if (degree[i] == 1) degOne++;
    if (degree[i] == 2) degTwo++;
    if (degree[i] == n - 1) degMore++;
  }
  if (degOne == 2 && degTwo == n - 2) {
    printf("bus topology\n");
  } else if (degTwo == n) {
    printf("ring topology\n");
  } else if (degMore == 1 && degOne == n - 1) {
    printf("star topology\n");
  } else {
    printf("unknown topology\n");
  }
}
