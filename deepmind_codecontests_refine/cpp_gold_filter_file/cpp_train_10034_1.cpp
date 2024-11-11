#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int M = 100005;
const int mod = 1e9 + 7;
const double eps = 1e-6;
const double Pi = 2 * acos(0.0);
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int bit(int x) { return 1 << x; }
inline double dabs(double x) { return x > 0 ? x : (-x); }
inline int abs(int x) { return x > 0 ? x : (-x); }
inline int lowbit(int x) { return x & (-x); }
int n, rec[15], tmp[20];
bool use[M];
struct node {
  int a, b, c, d;
  node(int x, int y, int z, int w) { a = x, b = y, c = z, d = w; }
};
set<int> st;
vector<node> v;
int tail = 0, able[400], num;
int first(int x) {
  if (x >= 100) return x / 100;
  if (x > 9) return x / 10;
  return x;
}
void deal(int x) {
  tmp[num++] = x % 10;
  x /= 10;
  while (x) {
    tmp[num++] = x % 10;
    x /= 10;
  }
}
bool check(int x, int y, int z, int w) {
  num = 0;
  deal(x);
  deal(y);
  deal(z);
  deal(w);
  for (int i = 0; i < num / 2; i++) {
    if (tmp[i] != tmp[num - 1 - i]) return 0;
  }
  memset(use, 0, sizeof(use));
  int tt = 0;
  for (int i = 0; i < num; i++) {
    if (!use[tmp[i]]) {
      use[tmp[i]] = 1;
      tt++;
    }
  }
  return tt == n;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> rec[i];
    st.insert(rec[i]);
  }
  if (n > 6) {
    cout << 0;
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        st.insert(rec[i] * 10 + rec[j]);
        for (int k = 0; k < n; k++) {
          int t = rec[i] * 100 + rec[j] * 10 + rec[k];
          if (t < 256) st.insert(t);
        }
      }
    }
    for (set<int>::iterator ii = st.begin(); ii != st.end(); ii++) {
      able[tail++] = *ii;
    }
    for (int i = 0; i < tail; i++) {
      for (int j = 0; j < tail; j++) {
        if (first(able[i]) != able[j] % 10) continue;
        for (int k = 0; k < tail; k++) {
          for (int l = 0; l < tail; l++) {
            if (check(able[j], able[l], able[k], able[i])) {
              v.push_back(node(able[i], able[k], able[l], able[j]));
            }
          }
        }
      }
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
      printf("%d.%d.%d.%d\n", v[i].a, v[i].b, v[i].c, v[i].d);
    }
  }
  return 0;
}
