#include <bits/stdc++.h>
using namespace std;
const int N = 1003;
int n, m, q;
int R[N * N];
int D[N * N];
int val[N * N];
int access(int x, int y) {
  int ret = 0;
  for (int(i) = (0); !((i) == (x)); (x) > (0) ? (i)++ : (i)--) {
    ret = D[ret];
  }
  for (int(i) = (0); !((i) == (y)); (y) > (0) ? (i)++ : (i)--) {
    ret = R[ret];
  }
  return ret;
}
void stuffr(int a, int b, int w, int h) {
  for (int p = a, pp = b, cnt = 0; cnt < w;
       swap(D[p], D[pp]), cnt++, p = R[p], pp = R[pp])
    ;
}
void stuffd(int a, int b, int w, int h) {
  for (int p = a, pp = b, cnt = 0; cnt < h;
       swap(R[p], R[pp]), cnt++, p = D[p], pp = D[pp])
    ;
}
void print() {
  for (int p = D[0], cnt = 0; cnt < n; cnt++, p = D[p]) {
    for (int pp = R[p], cnt2 = 0; cnt2 < m; cnt2++, pp = R[pp]) {
      cout << val[pp] << " ";
    }
    cout << endl;
  }
  cout << endl;
}
int main(int argc, char* argv[]) {
  ios::sync_with_stdio(0);
  cin >> n >> m >> q;
  for (int(i) = (0); !((i) == (n)); (n) > (0) ? (i)++ : (i)--) {
    for (int(j) = (0); !((j) == (m)); (m) > (0) ? (j)++ : (j)--) {
      cin >> val[(i + 1) * N + j + 1];
    }
  }
  for (int(i) = (0); !((i) == (n + 1)); (n + 1) > (0) ? (i)++ : (i)--) {
    for (int(j) = (0); !((j) == (m + 1)); (m + 1) > (0) ? (j)++ : (j)--) {
      D[i * N + j] = (i + 1) * N + j;
      R[i * N + j] = i * N + j + 1;
    }
  }
  for (int(Q) = (0); !((Q) == (q)); (q) > (0) ? (Q)++ : (Q)--) {
    int a, b, c, d, w, h;
    cin >> a >> b >> c >> d >> h >> w;
    int x1, x2, x3, x4, x5, x6, x7, x8;
    x1 = D[access(a - 1, b - 1)];
    x2 = D[access(c - 1, d - 1)];
    x3 = R[access(a - 1, b - 1)];
    x4 = R[access(c - 1, d - 1)];
    x5 = R[access(a - 1 + h, b - 1)];
    x6 = R[access(c - 1 + h, d - 1)];
    x7 = D[access(a - 1, b - 1 + w)];
    x8 = D[access(c - 1, d - 1 + w)];
    stuffd(x1, x2, w, h);
    stuffr(x3, x4, w, h);
    stuffr(x5, x6, w, h);
    stuffd(x7, x8, w, h);
  }
  print();
  return 0;
}
