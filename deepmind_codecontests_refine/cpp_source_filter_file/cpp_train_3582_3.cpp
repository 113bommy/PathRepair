#include <bits/stdc++.h>
using namespace std;
int heap1[1024], heap2[1024];
int ans[1024];
int v[1024];
int tem[1024];
int main() {
  int x;
  int n;
  scanf(" %d", &n);
  int m = 2 * n;
  memset(heap1, 0, sizeof(heap1));
  memset(heap2, 0, sizeof(heap2));
  memset(tem, 0, sizeof(tem));
  for (int i = 0; i < m; i++) {
    scanf(" %d", &v[i]);
    tem[v[i]]++;
  }
  int dist1 = 0;
  int dist2 = 0;
  int n1, n2;
  for (int i = 10; i <= 99; i++) {
    if (tem[i] >= 2) {
      heap1[i] = 1;
      heap2[i] = 1;
      dist1++;
      dist2++;
      tem[i] -= 2;
    }
    if (tem[i] == 1) {
      if (dist1 <= dist2) {
        heap1[i] = 1;
        dist1++;
        tem[i]--;
      } else {
        heap2[i] = 1;
        dist2++;
        tem[i]--;
      }
    }
  }
  n1 = dist1;
  n2 = dist2;
  for (int i = 10; i <= 99; i++) {
    while (n1 < n && tem[i] > 0) {
      heap1[i]++;
      tem[i]--;
      n1++;
    }
    while (n2 < n && tem[i] > 0) {
      heap2[i]++;
      tem[i]--;
      n2++;
    }
  }
  printf("%d\n", dist1 * dist2);
  int print = 0;
  for (int i = 0; i < m; i++) {
    if (heap1[v[i]]) {
      if (print) printf(" ");
      print = 1;
      printf("1");
      heap1[v[i]]--;
    } else if (heap2[v[i]]) {
      if (print) printf(" ");
      print = 1;
      printf("2");
      heap2[v[i]]--;
    }
  }
  printf("\n");
  return 0;
}
