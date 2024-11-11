#include <bits/stdc++.h>
using namespace std;
const int Nx = 200005;
int ct[Nx], MMsize, A, B, tree[Nx * 4];
map<int, int> MM;
vector<int> pos[Nx];
int query(int a, int b, int key) {
  if (A <= a && b <= B) return tree[key];
  if (B < a || b < A) return 0;
  int m = (a + b) / 2;
  return query(a, m, key * 2) + query(m + 1, b, key * 2 + 1);
}
void insert(int a, int b, int key) {
  if (A < a || A > b) return;
  tree[key]++;
  if (a == b) return;
  int m = (a + b) / 2;
  insert(a, m, key * 2);
  insert(m + 1, b, key * 2 + 1);
}
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 1, v, p; i <= N; i++) {
    scanf("%d", &v);
    if (p = MM[v] == 0) p = MM[v] = ++MMsize;
    pos[p].push_back(i);
  }
  for (map<int, int>::iterator i = MM.begin(); i != MM.end(); i++) {
    int p = i->second;
    for (vector<int>::iterator j = pos[p].begin(); j != pos[p].end(); j++) {
      int v = *j;
      for (int k = 1; k < N; k++) {
        if ((k * (v - 1) + 2) > N) break;
        A = k * (v - 1) + 2;
        B = min(N, k * v + 1);
        ct[k] += query(1, N, 1);
      }
    }
    for (vector<int>::iterator j = pos[p].begin(); j != pos[p].end(); j++) {
      A = *j;
      insert(1, N, 1);
    }
  }
  for (int i = 1; i < N; i++) {
    printf("%d", ct[i]);
    if (i == (N - 1))
      putchar('\n');
    else
      putchar(32);
  }
  return 0;
}
