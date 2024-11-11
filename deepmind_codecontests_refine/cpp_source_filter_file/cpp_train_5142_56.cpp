#include <bits/stdc++.h>
using namespace std;
const int MAXN(101);
const int MAXE(5000010);
const int MAXK(100010);
const int MAXC(2);
const int INF((INT_MAX - 1) / 2);
const int BASE(20);
const double LIM(1e50);
const double EPS(1e-5);
const double PER(0.02);
const double MUL(3.5);
int IT;
template <typename T>
inline bool checkmax(T &a, const T &b) {
  return b > a ? ((a = b), true) : false;
}
template <typename T>
inline bool checkmin(T &a, const T &b) {
  return b < a ? ((a = b), true) : false;
}
template <typename T>
inline T ABS(T a) {
  return a < 0 ? -a : a;
}
int main() {
  for (int i = 0; i <= 8; ++i) printf("%d??<>%d\n", i + 1);
  printf("9??>>??0\n");
  printf("??<>1\n");
  for (int i = 0; i <= 9; ++i) printf("?%d>>%d?\n", i, i);
  printf("?>>??\n");
  printf(">>?\n");
}
