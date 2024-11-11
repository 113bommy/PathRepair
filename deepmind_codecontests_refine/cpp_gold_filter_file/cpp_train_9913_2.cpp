#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  bool flag = false;
  while (!isdigit(c)) {
    if (c == '-') flag = true;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
  if (flag) x = -x;
}
int n;
int p[1010], pos[1010];
int rmd[1010];
int mod;
inline bool query(vector<int> vec) {
  if (vec.size() == 1) return true;
  printf("? %d ", vec.size());
  for (unsigned int i = 0; i < vec.size(); ++i) printf("%d ", vec[i]);
  puts("");
  fflush(stdout);
  int x;
  read(x);
  return x;
}
inline int query(int x, int y) {
  vector<int> vec;
  vec.push_back(x);
  vec.push_back(y);
  return query(vec);
}
inline vector<int> Era(vector<int> &v, int x) {
  vector<int> vec;
  for (unsigned int i = 0; i < v.size(); ++i)
    if (v[i] != x) vec.push_back(v[i]);
  return vec;
}
inline void find(int l, int r) {
  vector<int> vec;
  for (int i = 1; i <= n; ++i)
    if (!p[i]) vec.push_back(i);
  for (int i = 1; i <= n; ++i)
    if (!p[i] && rmd[i] == l % mod && query(Era(vec, i))) {
      p[i] = l;
      pos[l] = i;
      break;
    }
  for (int i = 1; i <= n; ++i)
    if (!p[i] && rmd[i] == r % mod && query(Era(vec, i))) {
      p[i] = r;
      pos[r] = i;
      break;
    }
}
int main() {
  read(n);
  mod = 1;
  find(1, n);
  for (int i = 1; i <= n; ++i)
    if (!p[i]) rmd[i] = query(pos[1], i);
  mod = 2;
  for (int i = 2; i + i <= n; ++i) {
    find(i, n - i + 1);
    if (i == mod + mod) {
      for (int j = 1; j <= n; ++j)
        if (!p[j]) {
          int r = rmd[j];
          vector<int> ve;
          for (int k = 1; k <= mod + mod; ++k)
            if (k % (2 * mod) != r) ve.push_back(pos[k]);
          ve.push_back(j);
          if (query(ve)) rmd[j] += mod;
        }
      mod = mod + mod;
    }
  }
  if (p[1] > (n >> 1)) {
    for (int i = 1; i <= n; ++i) p[i] = n - p[i] + 1;
  }
  printf("! ");
  for (int i = 1; i <= n; ++i) printf("%d ", p[i]);
  puts("");
  return 0;
}
