#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, v1, v2, t1, t2;
  scanf("%d%d%d%d%d", &n, &v1, &v2, &t1, &t2);
  if ((n * v1 + 2 * t1) > (n * v2 + 2 * t2))
    printf("Second");
  else if ((n * v1 + 2 * t1) < (n * v2 + 2 * t2))
    printf("First");
  else
    printf("Friendship");
  return 0;
}
