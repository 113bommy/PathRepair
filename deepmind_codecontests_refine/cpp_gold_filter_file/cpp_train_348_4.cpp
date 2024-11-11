#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<pair<int, pair<int, int> > > H, V;
class Pile {
 public:
  int Remsiz;
  int startX, startY;
  vector<int> piece;
  Pile(int _x, int _y) {
    Remsiz = 0;
    startX = _x;
    startY = _y;
    piece = vector<int>();
  }
  void add(int l, int r) {
    piece.push_back(l);
    piece.push_back(r);
    Remsiz += r - l;
  }
  int partials(int D) {
    int v = 0;
    for (int i = 0; i < ((int)(piece).size()); i += 2)
      v += min(piece[i + 1], D) - min(D, piece[i]);
    return v;
  }
  void output(int D) {
    if (startX == 0)
      printf("%d %d %d %d\n", 0, startY, D, startY);
    else
      printf("%d %d %d %d\n", startX, 0, startX, D);
  }
};
int main(void) {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; i++) {
    int xb, yb, xe, ye;
    scanf("%d%d%d%d", &xb, &yb, &xe, &ye);
    if (xb > xe) swap(xb, xe);
    if (yb > ye) swap(yb, ye);
    if (xb == xe && yb == ye) continue;
    if (xb == xe) {
      V.push_back(make_pair(xb, make_pair(yb, 1)));
      V.push_back(make_pair(xb, make_pair(ye, -1)));
    }
    if (yb == ye) {
      H.push_back(make_pair(yb, make_pair(xb, 1)));
      H.push_back(make_pair(yb, make_pair(xe, -1)));
    }
  }
  sort(H.begin(), H.end());
  sort(V.begin(), V.end());
  int HasN = m, HasM = n, NimVal = ((m % 2 == 0) * n) ^ ((n % 2 == 0) * m),
      upY = 0, upX = 0;
  int lastX = 0, lastY = 0, lev = 0;
  vector<Pile> piece;
  Pile nowpile(0, 0);
  for (__typeof((H).begin()) it = (H).begin(); it != (H).end(); it++) {
    if (it->first != lastY) {
      if (lastY && lastX < n) nowpile.add(lastX, n);
      if (nowpile.Remsiz) piece.push_back(nowpile);
      if (it->first > lastY + 1) upY = lastY + 1;
      NimVal ^= n;
      NimVal ^= nowpile.Remsiz;
      nowpile = Pile(0, it->first);
      lastY = it->first;
      lastX = 0;
      HasN--;
    }
    if (lev == 0 && it->second.first > lastX)
      nowpile.add(lastX, it->second.first);
    lastX = it->second.first;
    lev += it->second.second;
  }
  if (lastY && lastX < n) nowpile.add(lastX, n);
  if (nowpile.Remsiz) {
    piece.push_back(nowpile);
    NimVal ^= nowpile.Remsiz;
  }
  if (lastY + 1 < m) upY = m - 1;
  if (upY) {
    nowpile = Pile(0, upY);
    nowpile.add(0, n);
    piece.push_back(nowpile);
  }
  lastX = lastY = lev = 0;
  nowpile = Pile(0, 0);
  for (__typeof((V).begin()) it = (V).begin(); it != (V).end(); it++) {
    if (it->first != lastX) {
      if (lastX && lastY < m) nowpile.add(lastY, m);
      if (nowpile.Remsiz) piece.push_back(nowpile);
      if (it->first > lastX + 1) upX = lastX + 1;
      NimVal ^= m;
      NimVal ^= nowpile.Remsiz;
      nowpile = Pile(it->first, 0);
      lastY = 0;
      lastX = it->first;
      HasM--;
    }
    if (lev == 0 && it->second.first > lastY)
      nowpile.add(lastY, it->second.first);
    lastY = it->second.first;
    lev += it->second.second;
  }
  if (lastX && lastY < m) nowpile.add(lastY, m);
  if (nowpile.Remsiz) {
    piece.push_back(nowpile);
    NimVal ^= nowpile.Remsiz;
  }
  if (lastX + 1 < n) upX = n - 1;
  if (upX) {
    nowpile = Pile(upX, 0);
    nowpile.add(0, m);
    piece.push_back(nowpile);
  }
  puts(NimVal ? "FIRST" : "SECOND");
  if (NimVal) {
    for (__typeof((piece).begin()) it = (piece).begin(); it != (piece).end();
         it++) {
      int R = it->Remsiz;
      if ((R ^ NimVal) <= R) {
        R = R - (R ^ NimVal);
        int l = 0, r = (it->startX == 0 ? n : m);
        while (l <= r) {
          int mid = (l + r) / 2, v = it->partials(mid);
          if (v < R) {
            l = mid + 1;
          } else if (v > R) {
            r = mid - 1;
          } else {
            it->output(mid);
            break;
          }
        }
        if (l <= r) break;
      }
    }
  }
}
