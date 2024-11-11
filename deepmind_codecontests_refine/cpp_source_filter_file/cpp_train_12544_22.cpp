#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
long long x[N], y[N], i, j, n;
bool p;
vector<int> vct[1010];
vector<int>::iterator it;
vector<int>::reverse_iterator rit;
inline int read() {
  int s = 0;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    ;
  do {
    s = s * 10 + c - '0';
  } while ((c = getchar()) >= '0' && c <= '9');
  return s;
}
inline int abs(int a) { return a > 0 ? a : -a; }
bool cmp(const int &a, const int &b) { return y[a] < y[b]; }
int main() {
  n = read();
  for (i = 1; i <= n; i++) {
    x[i] = read(), y[i] = read();
    vct[x[i] / 1000].push_back(i);
  }
  for (i = 0; i < 1000; i++) {
    if (vct[i].empty()) continue;
    p ^= 1;
    sort(vct[i].begin(), vct[i].end(), cmp);
    if (p)
      for (rit = vct[i].rbegin(); rit != vct[i].rend(); rit++)
        printf("%d ", (*rit));
    else
      for (it = vct[i].begin(); it != vct[i].end(); it++) printf("%d ", (*it));
  }
  return 0;
}
