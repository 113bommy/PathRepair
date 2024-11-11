#include <bits/stdc++.h>
using namespace std;
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int &x, int y, int mod = 1000000007) {
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et() {
  puts("-1");
  exit(0);
}
int b[222];
void fmain(int tid) {
  for (int i = 4; i <= 100; i++) {
    b[i] = i * (i - 1) * (i - 2) * (i - 3) / 24;
  }
  scanf("%d", &n);
  map<int, int> mp;
  for (int i = 70, x = n; i > 3; i--) {
    while (x >= b[i]) {
      mp[i]++;
      x -= b[i];
    }
  }
  int pre = 0;
  for (auto p : mp) {
    for (int(j) = 0; (j) < (int)(p.first - pre); (j)++) printf("a");
    for (int(j) = 0; (j) < (int)(p.second); (j)++) printf("b");
    pre += p.first;
  }
  printf(" aaaab");
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
