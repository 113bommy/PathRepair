#include <bits/stdc++.h>
struct Point {
  int x, y;
};
bool operator<(Point x, Point y) {
  return (abs(x.x) + abs(x.y) < abs(y.x) + abs(y.y));
}
bool operator>(Point x, Point y) {
  return (abs(x.x) + abs(x.y) > abs(y.x) + abs(y.y));
}
bool operator==(Point x, Point y) {
  return (abs(x.x) + abs(x.y) == abs(y.x) + abs(y.y));
}
int comparer(const void *x, const void *y) {
  if (*(Point *)x < *(Point *)y) return -1;
  if (*(Point *)x > *(Point *)y) return 1;
  return 0;
}
void moveto(Point x, Point y) {
  if (x.x != y.x) {
    printf("1 ");
    printf("%d %c\n", abs(x.x - y.x), (x.x < y.x ? 'R' : 'L'));
  }
  if (x.y != y.y) {
    printf("1 ");
    printf("%d %c\n", abs(x.y - y.y), (x.y < y.y ? 'U' : 'D'));
  }
}
int main(int argc, char const *argv[]) {
  Point coords[100001];
  int n;
  scanf("%d", &n);
  coords[0].x = coords[0].y = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &coords[i].x, &coords[i].y);
  }
  qsort(coords, n, sizeof(Point), comparer);
  int count = 0;
  for (int i = 0; i < n; ++i) {
    if (coords[i].x != 0 && coords[i].y != 0) {
      count += 6;
    } else
      count += 4;
  }
  printf("%d\n", count);
  coords[n].x = coords[n].y = 0;
  for (int i = 0; i < n; ++i) {
    moveto(coords[n], coords[i]);
    printf("2\n");
    moveto(coords[i], coords[n]);
    printf("3\n");
  }
  return 0;
}
