#include <bits/stdc++.h>
using namespace std;
const int N = 2000;
const int Pmid = 500;
struct GPOINT {
  int x, y;
  GPOINT() {}
  GPOINT(int _x, int _y) : x(_x), y(_y) {}
} car[N], kin;
int cc[N][N];
int main() {
  scanf("%d%d", &kin.x, &kin.y);
  for (int i = 1; i <= 666; i++) {
    scanf("%d%d", &car[i].x, &car[i].y);
    cc[car[i].x][car[i].y] = 1;
  }
  while (kin.x != Pmid || kin.y != Pmid) {
    if (kin.x < Pmid) {
      kin.x++;
      if (cc[kin.x][kin.y]) kin.x--;
    }
    if (kin.x > Pmid) {
      kin.x--;
      if (cc[kin.x][kin.y]) kin.x++;
    }
    if (kin.y < Pmid) {
      kin.y++;
      if (cc[kin.x][kin.y]) kin.y--;
    }
    if (kin.y > Pmid) {
      kin.y--;
      if (cc[kin.x][kin.y]) kin.y++;
    }
    printf("%d %d\n", kin.x, kin.y);
    fflush(stdout);
    int num, tox, toy;
    scanf("%d%d%d", &num, &tox, &toy);
    if (num <= 0) exit(0);
    cc[car[num].x][car[num].y] = 0;
    car[num] = GPOINT(tox, toy);
    cc[tox][toy] = 1;
  }
  int LU = 0, LD = 0, RU = 0, RD = 0;
  for (int i = 1; i <= 666; i++) {
    if (car[i].x < Pmid && car[i].y < Pmid) LU++;
    if (car[i].x > Pmid && car[i].y < Pmid) LD++;
    if (car[i].x < Pmid && car[i].y > Pmid) RU++;
    if (car[i].x > Pmid && car[i].y > Pmid) RD++;
  }
  int movx = 0, movy = 0;
  if (LU + LD + RU >= 500) movx = -1, movy = -1;
  if (LU + RD + RU >= 500) movx = -1, movy = 1;
  if (LU + LD + RD >= 500) movx = 1, movy = -1;
  if (LD + RU + RD >= 500) movx = 1, movy = 1;
  while (1 < kin.x && kin.x < 999 && 1 < kin.y && kin.y < 999) {
    kin.x += movx;
    kin.y += movy;
    if (cc[kin.x][kin.y]) kin.y -= movy;
    printf("%d %d\n", kin.x, kin.y);
    fflush(stdout);
    int num, tox, toy;
    scanf("%d%d%d", &num, &tox, &toy);
    if (num <= 0) exit(0);
    cc[car[num].x][car[num].y] = 0;
    car[num] = GPOINT(tox, toy);
    cc[tox][toy] = 1;
  }
  return 0;
}
