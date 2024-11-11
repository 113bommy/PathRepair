#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::getline;
using std::greater;
using std::lower_bound;
using std::make_pair;
using std::map;
using std::max;
using std::min;
using std::multimap;
using std::pair;
using std::priority_queue;
using std::queue;
using std::random_shuffle;
using std::set;
using std::sort;
using std::stack;
using std::string;
using std::stringstream;
using std::swap;
using std::unique;
using std::vector;
const int MAXN(50010);
const int MAXM(50010);
const int MAXE(100010);
const int MAXK(6);
const int HSIZE(131313);
const int SIGMA_SIZE(26);
const int MAXH(19);
const int INFI((INT_MAX - 1) >> 1);
const unsigned long long BASE(31);
const long long LIM(10000000);
const int INV(-10000);
const int MOD(1000000007);
const double EPS(1e-8);
template <typename T>
void checkmax(T &a, T b) {
  if (b > a) a = b;
}
template <typename T>
void checkmin(T &a, T b) {
  if (b < a) a = b;
}
template <typename T>
T ABS(const T &a) {
  return a < 0 ? -a : a;
}
int str[4];
int rec[4];
set<int> table[10010], ans;
set<int> st[4][4];
int cur;
int K;
void dfs(int len, int cnt) {
  if (len == 0) {
    for (int i = 0; i < cnt; ++i)
      for (int j = i; j < cnt; ++j) st[i][j].clear();
    for (int i = 0; i < cnt; ++i) st[i][i].insert(rec[i]);
    st[0][0].insert(-rec[0]);
    for (int i = 2; i <= cnt; ++i) {
      for (int j = 0; j + i - 1 < cnt; ++j) {
        int l = j, r = j + i - 1;
        for (int k = l; k < r; ++k) {
          set<int>::iterator it1 = st[l][k].begin(), it2 = st[l][k].end();
          set<int>::iterator it3 = st[k + 1][r].begin(),
                             it4 = st[k + 1][r].end();
          for (; it1 != it2; ++it1)
            for (; it3 != it4; ++it3) {
              int temp = *it1 + *it3;
              st[l][r].insert(temp);
              temp = *it1 - *it3;
              st[l][r].insert(temp);
              temp = *it1 * *it3;
              st[l][r].insert(temp);
            }
        }
      }
    }
    set<int>::iterator it1 = st[0][cnt - 1].begin(), it2 = st[0][cnt - 1].end();
    for (; it1 != it2; ++it1) table[cur].insert(*it1);
    return;
  }
  for (int i = 1; i <= len; ++i) {
    int temp = 0;
    for (int j = 0, k = 4 - len; j < i; ++j, ++k) {
      temp *= 10;
      temp += str[k];
    }
    rec[cnt] = temp;
    dfs(len - i, cnt + 1);
  }
}
void debug(int i) {
  printf("debug: %d\n\n", i);
  for (set<int>::iterator it = table[i].begin(); it != table[i].end(); ++it)
    printf("%04d\n", *it);
  printf("\ndebug end\n\n");
}
int main() {
  for (cur = 0; cur < 10000; ++cur) {
    int ti = cur;
    for (int j = 0; j < 4; ++j) {
      str[3 - j] = ti % 10;
      ti /= 10;
    }
    dfs(4, 0);
  }
  int m;
  while (~scanf("%d%d", &K, &m)) {
    ans.clear();
    set<int>::iterator it1, it2;
    for (int i = 0; ans.size() < m && i < 10000; ++i) {
      it1 = table[i].begin(), it2 = table[i].end();
      for (; it1 != it2 && ans.size() < m; ++it1) {
        int temp = abs(K - *it1);
        if (temp < 10000) ans.insert(temp * 10000 + i);
        temp = abs(K + *it1);
        if (ans.size() < m && temp < 10000) ans.insert(temp * 10000 + i);
      }
    }
    it2 = ans.end();
    for (it1 = ans.begin(); it1 != it2; ++it1) printf("%08d\n", *it1);
  }
  return 0;
}
