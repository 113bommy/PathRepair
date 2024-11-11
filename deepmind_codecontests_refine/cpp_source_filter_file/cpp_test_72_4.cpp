#include <bits/stdc++.h>
using namespace std;
template <typename Tp>
void read(Tp &num) {
  num = 0;
  auto f = 1;
  char c = getchar();
  while (!isdigit(c)) c == '-' ? f = -1 : 1, c = getchar();
  while (isdigit(c)) num = num * 10 + (c ^ 48), c = getchar();
  num *= f;
}
template <typename Tp, typename... etc>
void read(Tp &num, etc &...more) {
  read(num);
  read(more...);
}
const int MAX = 1E9;
int d1, d2, d3, d4, mid;
int main() {
  printf("? %d %d\n", 1, MAX);
  fflush(stdout);
  scanf("%d", &d1);
  printf("? %d %d\n", 1, 1);
  fflush(stdout);
  scanf("%d", &d2);
  mid = (MAX - d1 + d2 + 1) / 2;
  printf("? %d %d\n", MAX, mid);
  fflush(stdout);
  scanf("%d", &d3);
  printf("? %d %d\n", 1, mid);
  fflush(stdout);
  scanf("%d", &d4);
  printf("! %d %d %d %d\n", 1 + d4, d2 - d4 + 1, MAX - d3, MAX - (d1 - 1));
  fflush(stdout);
}
