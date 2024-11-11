#include <bits/stdc++.h>
using namespace std;
void read(int &x) {
  static char c;
  while (!isdigit(c = getchar()))
    ;
  x = c ^ 48;
  while (isdigit(c = getchar())) x = (x * 10) + (c ^ 48);
}
void read(long long &x) {
  static char c;
  while (!isdigit(c = getchar()))
    ;
  x = c ^ 48;
  while (isdigit(c = getchar())) x = (x * 10) + (c ^ 48);
}
const int N = 1005;
int n, tmp;
int X[N], Y[N];
int NX[N], NY[N];
vector<pair<pair<int, int>, pair<int, int> > > O;
void Work() {
  read(n);
  for (int i = 1; i <= n; ++i) read(tmp), X[tmp] = i, NX[i] = i;
  for (int i = 1; i <= n; ++i) read(tmp), Y[tmp] = i, NY[i] = i;
  for (int i = 1; i < n; ++i) {
    int x = X[i], y = Y[i];
    int px, py;
    for (px = 1; NX[px] != x; ++px)
      ;
    for (py = 1; NY[py] != y; ++py)
      ;
    if (px != i || py != i)
      O.push_back(make_pair(make_pair(i, py), make_pair(px, i)));
    swap(NX[i], NX[px]), swap(NY[i], NY[py]);
  }
  printf("%zd\n", O.size());
  for (auto I : O)
    printf("%d %d %d %d\n", I.first.first, I.first.second, I.second.first,
           I.second.second);
}
int main() { Work(); }
