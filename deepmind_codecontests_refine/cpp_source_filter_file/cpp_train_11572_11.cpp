#include <bits/stdc++.h>
using namespace std;
char a[150010];
char b[150010];
int dirx[150010];
int diry[150010];
int k = 0;
queue<int> A[27];
queue<int> B[27];
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", a);
  scanf("%s", b);
  for (int i = 0; i < n; i++) {
    int x = a[i] - 'a';
    if (a[i] != '?')
      A[x].push(i);
    else
      A[26].push(i);
    x = b[i] - 'a';
    if (b[i] != '?')
      B[x].push(i);
    else
      B[26].push(i);
  }
  for (int i = 0; i < 26; i++) {
    while (!A[i].empty() && !B[i].empty()) {
      int x, y;
      x = A[i].front();
      A[i].pop();
      y = B[i].front();
      B[i].pop();
      dirx[k] = x;
      diry[k] = y;
      k++;
    }
    while (!A[i].empty() && !B[26].empty()) {
      int x = A[i].front();
      A[i].pop();
      int y = B[26].front();
      B[26].pop();
      dirx[k] = x;
      diry[k] = y;
      k++;
    }
    while (!B[i].empty() && !A[26].empty()) {
      int y = B[i].front();
      B[i].pop();
      int x = A[26].front();
      A[26].pop();
      dirx[k] = x;
      diry[k] = y;
      k++;
    }
  }
  while (!A[26].empty() && !B[26].empty()) {
    int x = A[26].front();
    A[26].pop();
    int y = B[26].front();
    B[26].pop();
    dirx[k] = x;
    diry[k] = y;
    k++;
  }
  printf("%d\n", k);
  for (int i = 0; i < k; i++) printf("%d %d\n", dirx[i], diry[i]);
}
