#include <bits/stdc++.h>
using namespace std;
template <class T>
void pv(T a, T b) {
  for (T i = a; i != b; ++i) cout << *i << " ";
  cout << endl;
}
template <class T>
void pvp(T a, T b) {
  for (T i = a; i != b; ++i)
    cout << "(" << i->first << ", " << i->second << ") ";
  cout << endl;
}
template <class T>
void chmin(T &t, T f) {
  if (t > f) t = f;
}
template <class T>
void chmax(T &t, T f) {
  if (t < f) t = f;
}
int in_c() {
  int c;
  for (; (c = getchar()) <= ' ';) {
    if (!~c) throw ~0;
  }
  return c;
}
int in() {
  int x = 0, c;
  for (; (unsigned)((c = getchar()) - '0') >= 10;) {
    if (c == '-') return -in();
    if (!~c) throw ~0;
  }
  do {
    x = (x << 3) + (x << 1) + (c - '0');
  } while ((unsigned)((c = getchar()) - '0') < 10);
  return x;
}
long long In() {
  long long x = 0, c;
  for (; (unsigned)((c = getchar()) - '0') >= 10;) {
    if (c == '-') return -In();
    if (!~c) throw ~0;
  }
  do {
    x = (x << 3) + (x << 1) + (c - '0');
  } while ((unsigned)((c = getchar()) - '0') < 10);
  return x;
}
int Q, N;
int XS[100010];
int QX[100010], QY[100010];
char QT[100010][6];
int segn;
int cnt[400010];
long long sum[400010][5];
void merge(int a, int b, int c) {
  cnt[a] = cnt[b] + cnt[c];
  for (int i = 0; i < 5; i++) sum[a][i] = 0;
  for (int i = 0; i < 5; i++)
    sum[a][i] = sum[b][i] + sum[c][(i - cnt[b] % 5 + 5) % 5];
  return;
}
void add(int a) {
  a += segn;
  cnt[a] = 1;
  sum[a][0] = XS[a - segn];
  for (; a >>= 1;) merge(a, a << 1 | 0, a << 1 | 1);
}
void del(int a) {
  a += segn;
  cnt[a] = 0;
  sum[a][0] = 0;
  for (; a >>= 1;) merge(a, a << 1 | 0, a << 1 | 1);
}
int main() {
  scanf("%d", &Q);
  for (int i = 0; i < Q; i++) {
    scanf("%s", &QT[i]);
    if (!strcmp(QT[i], "add"))
      QX[i] = in(), XS[N++] = QX[i];
    else if (!strcmp(QT[i], "del"))
      QX[i] = in(), XS[N++] = QX[i];
    else
      QX[i] = QY[i] = -1;
  }
  sort(XS, XS + N);
  N = (unique(XS, XS + N) - XS);
  segn = 1;
  while (segn < N + 5) segn <<= 1;
  for (int i = 0; i < Q; i++)
    if (~QX[i]) {
      QY[i] = lower_bound(XS, XS + N, QX[i]) - XS;
    }
  for (int i = 0; i < Q; i++) {
    if (!strcmp(QT[i], "add"))
      add(QY[i]);
    else if (!strcmp(QT[i], "del"))
      del(QY[i]);
    else
      printf("%I64d\n", sum[1][2]);
  }
  return 0;
}
