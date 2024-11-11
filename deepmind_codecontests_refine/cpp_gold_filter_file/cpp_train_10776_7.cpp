#include <bits/stdc++.h>
using namespace std;
vector<int> graph[505];
int arr[505];
bool brr[505][505];
vector<int> aelements;
vector<int> belements;
vector<int> celements;
int main() {
  int a, b, n, m, i, j, k, l, c;
  scanf("%d", &n);
  scanf("%d", &m);
  for (i = 0; i < m; i++) {
    scanf("%d", &a);
    scanf("%d", &b);
    graph[a].push_back(b);
    graph[b].push_back(a);
    brr[a][b] = true;
    brr[b][a] = true;
  }
  fill(arr, arr + n + 2, 0);
  for (i = 1; i <= n; i++) {
    if ((long long int)(graph[i].size()) == (n - 1)) {
      arr[i] = 2;
      belements.push_back(i);
    }
  }
  for (i = 1; i <= n; i++) {
    if (arr[i] == 0) {
      arr[i] = 1;
      aelements.push_back(i);
      break;
    }
  }
  for (j = 0; j < (long long int)(graph[i].size()); j++) {
    int child = graph[i][j];
    if (arr[child] == 0) {
      arr[child] = 1;
      aelements.push_back(child);
    }
  }
  for (i = 1; i <= n; i++) {
    if (arr[i] == 0) {
      arr[i] = 3;
      celements.push_back(i);
    }
  }
  for (i = 0; i < (long long int)(aelements.size()); i++) {
    for (j = 0; j < (long long int)(belements.size()); j++) {
      if (!brr[aelements[i]][belements[j]]) {
        printf("No\n");
        return 0;
      }
    }
    for (j = 0; j < (long long int)(aelements.size()); j++) {
      if (i != j && !brr[aelements[i]][aelements[j]]) {
        printf("No\n");
        return 0;
      }
    }
  }
  for (i = 0; i < (long long int)(celements.size()); i++) {
    for (j = 0; j < (long long int)(belements.size()); j++) {
      if (!brr[celements[i]][belements[j]]) {
        printf("No\n");
        return 0;
      }
    }
    for (j = 0; j < (long long int)(celements.size()); j++) {
      if (i != j && !brr[celements[i]][celements[j]]) {
        printf("No\n");
        return 0;
      }
    }
  }
  for (i = 0; i < (long long int)(celements.size()); i++) {
    for (j = 0; j < (long long int)(aelements.size()); j++) {
      if (brr[celements[i]][aelements[j]]) {
        printf("No\n");
        return 0;
      }
    }
  }
  printf("Yes\n");
  for (i = 1; i <= n; i++) {
    if (arr[i] == 1)
      printf("a");
    else if (arr[i] == 2)
      printf("b");
    else
      printf("c");
  }
  printf("\n");
  return 0;
}
