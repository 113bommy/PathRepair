#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T min(T &a, T &b) {
  return a < b ? a : b;
}
template <class T>
inline T max(T &a, T &b) {
  return a > b ? a : b;
}
template <class T>
void read(T &x) {
  char ch;
  while ((ch = getchar()) && !isdigit(ch))
    ;
  x = ch - '0';
  while ((ch = getchar()) && isdigit(ch)) x = x * 10 + ch - '0';
}
struct point {
  int x, y;
  point() {}
  point(int _x, int _y) : x(_x), y(_y) {}
};
int main() {
  for (int i = 0; i <= 9; i++) printf("??%d>>%d??", i);
  puts("??>>?");
  for (int i = 0; i <= 8; i++) printf("%d?<>%d", i, i + 1);
  puts("9?>>?0");
  puts("?<>1");
  puts(">>??");
}
