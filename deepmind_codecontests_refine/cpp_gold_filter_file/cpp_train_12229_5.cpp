#include <bits/stdc++.h>
using namespace std;
struct chache {
  int np;
  int no;
  int nz;
  int pos;
};
int ne[500];
long long mod;
map<chache, int> mem;
bool operator<(const chache &a, const chache &b) {
  if (a.no < b.no) return true;
  if (a.no > b.no) return false;
  if (a.np < b.np) return true;
  if (a.np > b.np) return false;
  if (a.nz < b.nz) return true;
  if (a.nz > b.nz) return false;
  if (a.pos < b.pos) return true;
  return false;
}
long long f(int np, int no, int nz, int pos) {
  long long res = 0;
  chache tmp;
  tmp.no = no;
  tmp.np = np;
  tmp.nz = nz;
  tmp.pos = pos;
  if (pos == -1) return 1;
  if (mem.count(tmp)) return mem[tmp];
  if (ne[pos] == 0) res += f(np, no, nz, pos - 1);
  if (ne[pos] == 1) {
    if (no != 0) res += no * f(np + 1, no - 1, nz, pos - 1);
    if (nz != 0) res += nz * f(np, no + 1, nz - 1, pos - 1);
  }
  if (ne[pos] == 2) {
    if (no >= 2) res += no * (no - 1) / 2 * f(np + 2, no - 2, nz, pos - 1);
    if (nz >= 2) res += nz * (nz - 1) / 2 * f(np, no + 2, nz - 2, pos - 1);
    if (nz >= 1 && no >= 1) res += no * nz * f(np + 1, no, nz - 1, pos - 1);
  }
  mem[tmp] = res % mod;
  return mem[tmp];
}
int main() {
  int n, m;
  char temp;
  cin >> n >> m >> mod;
  for (int i = 0; i < n; ++i) ne[i] = 2;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> temp;
      if (temp != '0') ne[j]--;
    }
  }
  cout << f(0, 0, n - m, n - 1);
  return 0;
}
