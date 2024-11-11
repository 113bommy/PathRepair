#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
bool mmap[maxn][maxn];
inline void cmp(string a, string b) {
  int len = min(a.length(), b.length());
  for (int i = 0; i < len; ++i) {
    if (a[i] != b[i]) {
      mmap[a[i] - 'a' + 1][b[i] - 'a' + 1] = true;
      return;
    }
  }
  if (a.length() > b.length()) {
    puts("Impossible");
    exit(0);
  }
}
struct ss {
  char c;
  int siz;
  inline bool operator<(const ss& other) const {
    return this->siz > other.siz ||
           (this->siz == other.siz && this->c < other.c);
  }
} sxd[maxn];
int main() {
  int n;
  cin >> n;
  string lst;
  cin >> lst;
  string now;
  memset(mmap, 0, sizeof(mmap));
  for (int i = 2; i <= n; ++i) {
    cin >> now;
    cmp(lst, now);
    lst = now;
  }
  for (int k = 1; k <= 26; ++k)
    for (int i = 1; i <= 26; ++i)
      for (int j = 1; j <= 26; ++j) mmap[i][j] |= mmap[i][k] & mmap[k][j];
  for (int i = 1; i <= 26; ++i) {
    if (mmap[i][i]) {
      puts("Impossible");
      return 0;
    }
  }
  for (int i = 1; i <= 26; ++i) {
    sxd[i].c = i + 'a' - 1;
    sxd[i].siz = 0;
    for (int j = 1; j <= 26; ++j) sxd[i].siz += mmap[i][j];
  }
  sort(sxd + 1, sxd + 26);
  for (int i = 1; i <= 26; ++i) putchar(sxd[i].c);
  return 0;
}
