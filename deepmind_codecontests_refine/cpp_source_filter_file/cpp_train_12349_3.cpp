#include <bits/stdc++.h>
using namespace std;
template <class T1>
void deb(T1 e1) {
  cout << e1 << endl;
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cout << e1 << " " << e2 << endl;
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cout << e1 << " " << e2 << " " << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
       << endl;
}
double dp[50 + 7][5000 + 7], E;
bool mark[50 + 7][5000 + 7];
int n, r;
int p1[50 + 7], p2[50 + 7];
pair<int, int> arr[50 + 7];
double rec(int pos, int taken) {
  if (taken > r) return ((double)taken + E);
  if (pos >= n) return (double)taken;
  double &ret = dp[pos][taken];
  if (mark[pos][taken]) return ret;
  mark[pos][taken] = 1;
  ret = (double)p1[pos] * rec(pos + 1, taken + arr[pos].first);
  ret += (double)p2[pos] * rec(pos + 1, taken + arr[pos].second);
  ret /= 100.0;
  return ret = min(ret, (double)taken + E);
}
int main() {
  int v;
  scanf("%d %d", &n, &r);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &arr[i].first, &arr[i].second);
    scanf("%d", &v);
    p1[i] = v;
    p2[i] = 100 - v;
  }
  double ans;
  double l = 1.0, h = 100000.0;
  for (int i = 0; i < 200; i++) {
    E = (l + h) / 2.0;
    memset((mark), 0, sizeof(mark));
    double ret = rec(0, 0);
    if (ret < E) {
      h = E;
    } else {
      l = E;
    }
  }
  printf("%.12f\n", E);
  return 0;
}
