#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001000;
struct Node {
  int a, g, id;
  bool friend operator<(Node x, Node y) { return x.a < y.a; }
};
Node node[maxn];
int main() {
  int n;
  map<int, int> ans;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &node[i].a, &node[i].g);
    node[i].id = i;
  }
  sort(node + 1, node + n + 1);
  int left = 1, right = n, suma = 0, sumg = 0;
  while (left <= right) {
    if (suma + node[left].a > 500) {
      ans[node[right].id] = 2;
      suma -= node[right].g;
      right--;
    } else {
      ans[node[left].id] = 1;
      suma += node[left].a;
      left++;
    }
  }
  if (suma > 500 || suma < -500)
    puts("-1");
  else {
    for (int i = 1; i <= n; i++) {
      if (ans[i] == 1)
        printf("A");
      else
        printf("G");
    }
    puts("");
  }
}
