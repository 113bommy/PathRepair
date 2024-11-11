#include <bits/stdc++.h>
int main() {
  int user, size, prod;
  int que[104];
  int i;
  int ttl;
  int time = 0;
  scanf("%d%d%d", &user, &size, &prod);
  ttl = user * size;
  for (i = 1; i <= prod; i++) {
    int id;
    scanf("%d", &id);
    que[id] = i;
  }
  for (i = 0; i < ttl; i++) {
    int id;
    int j;
    scanf("%d", &id);
    int pos = que[id];
    for (j = 1; j <= prod; j++) {
      if (que[j] < pos) que[j]++;
    }
    que[id] = 1;
    time += pos;
  }
  printf("%d\n", time);
}
