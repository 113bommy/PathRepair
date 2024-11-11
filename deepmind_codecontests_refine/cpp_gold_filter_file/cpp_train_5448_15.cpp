#include <bits/stdc++.h>
#pragma comment(linker, "/stack:64000000")
template <typename T>
inline void SWAP(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}
template <typename T>
inline T ABS(const T &VAL) {
  return VAL < 0 ? -VAL : VAL;
}
template <typename T>
inline T MAX(const T &a, const T &b) {
  return a < b ? b : a;
}
template <typename T>
inline T MIN(const T &a, const T &b) {
  return a < b ? a : b;
}
template <typename T>
inline T SQR(const T &a) {
  return a * a;
}
const int INTinf = 1000000005;
const int nINTinf = 0 - 2147483648;
const long long LLinf = 9223372036854775807LL;
using namespace std;
int n, m;
int a[2000005];
int st[1000005];
struct pt {
  int x, cNom, val;
  pt(int x, int cNom, int val) {
    this->x = x;
    this->cNom = cNom;
    this->val = val;
  }
};
queue<pt> q;
int main() {
  cin >> n >> m;
  for (int i = 0; i != n; i++) {
    scanf("%d", a + i);
    a[i + n] = a[i];
  }
  for (int i = 0; i != 1000005; i++) {
    st[i] = -1;
  }
  for (int i = 0; i != m; i++) {
    int t;
    scanf("%d", &t);
    st[t] = i;
  }
  int to = n << 1;
  int sost = 0;
  int nsost = -1;
  int mx = 0;
  for (int i = 0; i != to; i++) {
    if (nsost >= st[a[i]]) {
      nsost = st[a[i]];
      ++sost;
    } else {
      nsost = st[a[i]];
    }
    if (nsost != -1) {
      while (!q.empty() &&
             ((q.front().cNom < sost - 1) ||
              ((q.front().cNom == sost - 1) && (q.front().x <= nsost)))) {
        pt val = q.front();
        q.pop();
        mx = MAX(mx, i - val.val);
      }
      q.push(pt(nsost, sost, i));
    } else {
      while (!q.empty()) {
        mx = MAX(mx, i - q.front().val);
        q.pop();
      }
    }
  }
  cout << mx << endl;
  return 0;
}
