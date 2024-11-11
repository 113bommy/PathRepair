#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, v1, v2, p1, p2;
  scanf("%d%d%d%d%d", &s, &v1, &v2, &p1, &p2);
  if (v1 * s + p1 * 2 > v2 * s + p2 * 2) printf("First\n");
  if (v1 * s + p1 * 2 < v2 * s + p2 * 2) printf("Second\n");
  if (v1 * s + p1 * 2 == v2 * s + p2 * 2) printf("Friendship\n");
  return 0;
}
