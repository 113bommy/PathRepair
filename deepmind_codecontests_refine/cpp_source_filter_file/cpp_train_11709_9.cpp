#include <bits/stdc++.h>
using namespace std;
const int inf = int(1e9);
const double eps = 1e-4;
const double pi = 4 * atan(double(1));
const int N = 2020;
char buf[N];
int tmp[N], num[N];
bitset<N> val[N], used[N];
vector<int> ans;
inline void build(int num) {
  int n = (int)strlen(buf);
  for (int i = 0; i < n; ++i) {
    tmp[i] = buf[i] - '0';
  }
  reverse(tmp, tmp + n);
  int ptr = 0;
  while (n > 0) {
    if (tmp[0] % 2 != 0) {
      val[num].set(ptr);
    }
    ++ptr;
    int ost = 0;
    for (int j = n - 1; j >= 0; --j) {
      tmp[j] += ost * 2;
      ost = tmp[j] % 2;
      tmp[j] /= 2;
    }
    while (n > 0 && tmp[n - 1] == 0) {
      --n;
    }
  }
}
int main() {
  int n;
  cin >> n;
  gets(buf);
  for (int i = 0; i < N; ++i) {
    num[i] = -1;
  }
  for (int i = 0; i < n; ++i) {
    gets(buf);
    build(i);
    bool good = true;
    for (int j = 0; j < N; ++j) {
      if (!val[i].test(j)) {
        continue;
      }
      if (num[j] == -1) {
        num[j] = i;
        good = false;
        break;
      }
      val[i] ^= val[num[j]];
      used[i] ^= used[num[j]];
    }
    if (good) {
      ans.clear();
      for (int j = 0; j < N; ++j) {
        if (used[i].test(j)) {
          ans.push_back(j);
        }
      }
      printf("%d", int((ans).size()));
      for (int j = 0; j < int((ans).size()); ++j) {
        printf(" %d", ans[j]);
      }
      puts("");
    } else {
      used[i].set(i);
      puts("0");
    }
  }
  return 0;
}
