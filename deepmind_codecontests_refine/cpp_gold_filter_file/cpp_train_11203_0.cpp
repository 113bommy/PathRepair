#include <bits/stdc++.h>
using namespace std;
int perm[100001];
int n;
struct node {
  int id, num;
  bool operator<(node other) const { return num < other.num; }
} info[100001];
int ret[100001];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &perm[i]);
  for (int i = 0; i < n; i++)
    info[i].id = i, info[i].num = perm[i] + perm[(i + 1) % n];
  sort(info, info + n);
  for (int i = 0; i < n; i++) ret[info[i].id] = i;
  for (int i = 0; i < n; i++) printf("%d ", ret[i]);
  return 0;
}
