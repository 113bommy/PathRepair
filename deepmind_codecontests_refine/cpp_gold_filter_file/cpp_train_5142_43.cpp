#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:128777216")
const int null = 0;
using namespace std;
template <class T>
int size(const T &a) {
  return int(a.size());
}
template <class T>
T abs(const T &a) {
  return (a < 0 ? -a : a);
}
template <class T>
T sqr(const T &a) {
  return a * a;
}
int main() {
  for (int i = 0; i < 9; i++) {
    printf("%d??<>%d\n", i, i + 1);
  }
  printf("9??>>??0\n");
  printf("??<>1\n");
  for (int i = 0; i < 10; i++) {
    printf("?%d>>%d?\n", i, i);
  }
  printf("?>>??\n");
  printf(">>?\n");
  return 0;
}
