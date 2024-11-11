#include <bits/stdc++.h>
using namespace std;
string s1, s2, s3, s4;
int king[][2] = {{-1, 0}, {+1, 0},  {0, -1}, {0, +1},
                 {1, 1},  {-1, -1}, {-1, 1}, {1, -1}};
pair<int, int> rook1, rook2, w, b;
pair<int, int> format(string a) {
  return make_pair(a[1] - '0', a[0] - 'a' + 1);
}
bool horizontal(pair<int, int> w, pair<int, int> kill) {
  pair<int, int> block = ::w;
  if (w.first != kill.first) return 0;
  if (w.first != block.first) return 1;
  if (min(w.second, kill.second) < block.second &&
      block.second < max(w.second, kill.second))
    return 0;
  return 1;
}
bool vertikal(pair<int, int> w, pair<int, int> kill) {
  pair<int, int> block = ::w;
  if (w.second != kill.second) return 0;
  if (w.second != block.second) return 1;
  if (min(w.first, kill.first) < block.first &&
      block.first < max(w.first, kill.first))
    return 0;
  return 1;
}
int isattacked(pair<int, int> pos) {
  if (horizontal(rook1, pos) && pos != rook1 ||
      horizontal(rook2, pos) && pos != rook2)
    return 1;
  if (vertikal(rook1, pos) && pos != rook1 ||
      vertikal(rook2, pos) && pos != rook2)
    return 1;
  for (int i = 0; i < 8; ++i) {
    int nr = w.first + king[i][0];
    int nc = w.second + king[i][1];
    if (nr < 1 || nc < 1 || nr > 8 || nc > 8) continue;
    if (make_pair(nr, nc) == pos) return 1;
  }
  return 0;
}
int main() {
  cin >> s1 >> s2 >> s3 >> s4;
  rook1 = format(s1);
  rook2 = format(s2);
  w = format(s3);
  b = format(s4);
  bool exit = false;
  for (int i = 0; i < 8; ++i) {
    int nr = b.first + king[i][0];
    int nc = b.second + king[i][1];
    pair<int, int> w = make_pair(nr, nc);
    if (nr < 1 || nc < 1 || nr > 8 || nc > 8) continue;
    if (isattacked(make_pair(nr, nc)) == false) exit = true;
  }
  if (isattacked(b) && exit == false)
    printf("CHECKMAKTE\n");
  else
    printf("OTHER\n");
  return 0;
}
