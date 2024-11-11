#include <bits/stdc++.h>
int main() {
  int s, v1, v2, t1, t2;
  int first, second;
  scanf("%d %d %d %d %d", &s, &v1, &v2, &t1, &t2);
  first = s * v1 + 2 * t1;
  second = s * v2 + 2 * t2;
  if (first == second)
    printf("Friendship");
  else if (first > second)
    printf("First");
  else if (first < second)
    printf("Second");
  return 0;
}
