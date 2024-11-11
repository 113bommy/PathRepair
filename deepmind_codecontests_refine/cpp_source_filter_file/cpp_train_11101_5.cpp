#include <bits/stdc++.h>
template <typename T>
inline void read(T &x) {
  char c;
  bool nega = 0;
  while ((!isdigit(c = getchar())) && (c != '-'))
    ;
  if (c == '-') {
    nega = 1;
    c = getchar();
  }
  x = c - 48;
  while (isdigit(c = getchar())) x = x * 10 + c - 48;
  if (nega) x = -x;
}
template <typename T>
inline void writep(T x) {
  if (x > 9) writep(x / 10);
  putchar(x % 10 + 48);
}
template <typename T>
inline void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  writep(x);
  putchar(' ');
}
template <typename T>
inline void writeln(T x) {
  write(x);
  putchar('\n');
}
using namespace std;
int n;
vector<int> p[1000005];
void setup() {
  read(n);
  p[0].push_back(1);
  p[1].push_back(0);
  p[1].push_back(1);
  for (int i = (2); i <= (n); i++) {
    p[i] = p[i - 1];
    p[i].insert(p[i].begin(), 0);
    for (int j = (0); j <= (int(p[i - 2].size()) - 1); j++)
      p[i][j] = (p[i][j] + p[i - 2][j]) % 2;
  }
  writeln(p[n].size());
  for (int i = (0); i <= (int(p[n].size()) - 1); i++) write(p[n][i]);
  putchar('\n');
  n--;
  writeln(p[n].size());
  for (int i = (0); i <= (int(p[n].size()) - 1); i++) write(p[n][i]);
}
void work() {}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  setup();
  work();
  return 0;
}
