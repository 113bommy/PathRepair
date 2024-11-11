#include <bits/stdc++.h>
using namespace std;
int ar[100100];
int din[100100];
int ifpoeifoprfirofi[400100];
int jfdslkgjlkfdgjdl[400100];
int n;
void build_min(int v, int l, int r) {
  if (l == r)
    ifpoeifoprfirofi[v] = l;
  else {
    int m = (l + r) / 2;
    build_min((v << 1), l, m);
    build_min((v << 1) + 1, m + 1, r);
    if (ar[ifpoeifoprfirofi[v << 1]] < ar[ifpoeifoprfirofi[(v << 1) + 1]])
      ifpoeifoprfirofi[v] = ifpoeifoprfirofi[v << 1];
    else
      ifpoeifoprfirofi[v] = ifpoeifoprfirofi[(v << 1) + 1];
  }
}
int getmin(int v, int tl, int tr, int l, int r) {
  if (l > r) return n + 1;
  if (l == tl && r == tr) return ifpoeifoprfirofi[v];
  int m = (tl + tr) / 2;
  int a = getmin(v << 1, tl, m, l, ((r) < (m) ? (r) : (m)));
  int b = getmin((v << 1) + 1, m + 1, tr, ((l) > (m + 1) ? (l) : (m + 1)), r);
  if (ar[a] < ar[b])
    return a;
  else
    return b;
}
void build_max(int v, int l, int r) {
  if (l == r)
    jfdslkgjlkfdgjdl[v] = l;
  else {
    int m = (l + r) / 2;
    build_max((v << 1), l, m);
    build_max((v << 1) + 1, m + 1, r);
    if (ar[jfdslkgjlkfdgjdl[v << 1]] > ar[jfdslkgjlkfdgjdl[(v << 1) + 1]])
      jfdslkgjlkfdgjdl[v] = jfdslkgjlkfdgjdl[v << 1];
    else
      jfdslkgjlkfdgjdl[v] = jfdslkgjlkfdgjdl[(v << 1) + 1];
  }
}
int getmax(int v, int tl, int tr, int l, int r) {
  if (l > r) return n;
  if (l == tl && r == tr) return jfdslkgjlkfdgjdl[v];
  int tm = (tl + tr) / 2;
  int a = getmax(v << 1, tl, tm, l, ((r) < (tm) ? (r) : (tm)));
  int b =
      getmax((v << 1) + 1, tm + 1, tr, ((l) > (tm + 1) ? (l) : (tm + 1)), r);
  if (ar[a] > ar[b])
    return a;
  else
    return b;
}
int main(int argc, char** argv) {
  int k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> ar[i];
  ar[n] = 0;
  ar[n + 1] = INT_MAX;
  build_min(1, 0, n - 1);
  build_max(1, 0, n - 1);
  int lastmin = 0;
  int lastmax = 0;
  int left = 0;
  int dinmax = 0;
  int ndinmax = 1;
  for (int i = 0; i < n; ++i) {
    if (ar[i] > ar[lastmax]) lastmax = i;
    if (ar[i] < ar[lastmin]) lastmin = i;
    while (ar[lastmax] - ar[lastmin] > k) {
      if (lastmax < lastmin) {
        left = lastmax + 1;
        lastmax = getmax(1, 0, n - 1, left, i);
      } else {
        left = lastmin + 1;
        lastmin = getmin(1, 0, n - 1, left, i);
      }
    }
    din[i] = i - left + 1;
    if (din[i] == dinmax) ndinmax++;
    if (din[i] > dinmax) {
      dinmax = din[i];
      ndinmax = 1;
    }
  }
  cout << dinmax << " " << ndinmax << endl;
  for (int i = 0; i < n; ++i)
    if (din[i] == dinmax) cout << i - dinmax + 2 << " " << i + 1 << endl;
  return 0;
}
