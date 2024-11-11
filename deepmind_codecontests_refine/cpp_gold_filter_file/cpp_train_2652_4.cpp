#include <bits/stdc++.h>
using namespace std;
const int constant = 320;
int m, t, r, visit[1000], night[1000], q, total;
bool used[1000];
void print(int x) {
  for (int i = 0; i < (t); i++) night[x + i]++;
}
int main() {
  scanf("%d %d %d", &m, &t, &r);
  for (int i = 0; i < (m); i++) scanf("%d", &visit[i]);
  for (int i = 0; i < (m); i++) visit[i] += constant;
  for (int i = 0; i < (m); i++) {
    q = 0;
    while (night[visit[i]] < r) {
      if (q > visit[i] || t - 1 < q) {
        printf("-1\n");
        return 0;
      }
      if (!used[visit[i] - q]) {
        total++;
        print(visit[i] - q);
        q++;
      } else
        q++;
    }
  }
  printf("%d\n", total);
  return 0;
}
