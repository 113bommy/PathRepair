#include <bits/stdc++.h>
using namespace std;
template <typename IntType>
void read(IntType& val) {
  val = 0;
  int c;
  bool inv = false;
  while (!isdigit(c = getchar()))
    if (c == '-') inv = true;
  do {
    val = (val << 1) + (val << 3) + c - '0';
  } while (isdigit(c = getchar()));
  if (inv) val = -val;
}
template <>
void read<string>(string& str) {
  str.clear();
  int c;
  while (iscntrl(c = getchar()) || c == ' ' || c == '\t')
    ;
  do {
    str.push_back(c);
  } while (!(iscntrl(c = getchar()) || c == ' ' || c == '\t'));
}
const int MaxN = 1e6 + 10;
int n, m;
void printext(int n, int m, int offx = 0) {
  if (n <= 0)
    return;
  else if (n == 1) {
    for (int i = (1); i <= (m / 2); ++i)
      printf("%d %d\n%d %d\n", offx + 1, i, offx + 1, m - i + 1);
    if (m & 1) printf("%d %d\n", offx + 1, m / 2 + 1);
  } else {
    for (int i = (1); i <= (m); ++i)
      printf("%d %d\n%d %d\n", offx + 1, i, n - offx, m - i + 1);
    printext(n - 2, m, offx + 1);
  }
}
int main(int argc, char* argv[]) {
  read(n);
  read(m);
  printext(n, m);
  return 0;
}
