#include <bits/stdc++.h>
using namespace std;
static const int INF = 500000000;
template <class T>
void debug(T a, T b) {
  for (; a != b; ++a) cerr << *a << ' ';
  cerr << endl;
}
int main() {
  for (int i = 0; i < 10; ++i) printf("??%d>>%d??\n", i, i);
  for (int i = 0; i < 9; ++i) printf("%d??<>%d\n", i, i + 1);
  puts("9??>>?0");
  for (int i = 0; i < 9; ++i) printf("%d?<>%d\n", i, i + 1);
  puts("9?>>?0");
  puts("?<>1");
  puts(">>??");
  return 0;
}
