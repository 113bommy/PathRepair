#include <bits/stdc++.h>
using namespace std;
int graph[20][3];
bool mem[1 << 20 + 1];
bool m[1 << 20 + 1];
int f(int mask) {
  if (__builtin_popcount(mask) == 20) return false;
  if (m[mask]) return mem[mask];
  m[mask] = 1;
  bool won = false;
  for (int i = 1; i < 20; i++)
    if ((mask & (1 << i)) == 0) {
      won = won | !f(mask | (1 << i));
      for (int j = 0; j < 3; j++) {
        int l = graph[i][j];
        int temp = mask | (1 << i);
        while ((temp & (1 << l)) == 0) {
          temp |= (1 << l);
          won |= !f(temp);
          l = graph[l][j];
        }
      }
    }
  return mem[mask] = won;
}
int main() {
  graph[1][0] = 0;
  graph[2][0] = 0;
  graph[3][0] = 0;
  graph[4][0] = 0;
  graph[5][0] = 1;
  graph[6][0] = 2;
  graph[7][0] = 3;
  graph[8][0] = 0;
  graph[9][0] = 4;
  graph[10][0] = 5;
  graph[11][0] = 6;
  graph[12][0] = 7;
  graph[13][0] = 8;
  graph[14][0] = 9;
  graph[15][0] = 10;
  graph[16][0] = 11;
  graph[17][0] = 13;
  graph[18][0] = 14;
  graph[19][0] = 15;
  graph[1][1] = 0;
  graph[2][1] = 0;
  graph[3][1] = 0;
  graph[4][1] = 1;
  graph[5][1] = 2;
  graph[6][1] = 3;
  graph[7][1] = 0;
  graph[8][1] = 4;
  graph[9][1] = 5;
  graph[10][1] = 6;
  graph[11][1] = 7;
  graph[12][1] = 0;
  graph[13][1] = 9;
  graph[14][1] = 10;
  graph[15][1] = 11;
  graph[16][1] = 12;
  graph[17][1] = 14;
  graph[18][1] = 15;
  graph[19][1] = 16;
  graph[2][2] = 2;
  graph[2][2] = 3;
  graph[3][2] = 0;
  graph[4][2] = 5;
  graph[5][2] = 6;
  graph[6][2] = 7;
  graph[7][2] = 0;
  graph[8][2] = 9;
  graph[9][2] = 10;
  graph[10][2] = 11;
  graph[11][2] = 12;
  graph[12][2] = 0;
  graph[13][2] = 14;
  graph[14][2] = 15;
  graph[15][2] = 16;
  graph[16][2] = 0;
  graph[17][2] = 18;
  graph[18][2] = 19;
  graph[19][2] = 0;
  char c;
  int pos = 1;
  for (int i = 1; i <= 19; i++) {
    cin >> c;
    if (c == '.') pos |= (1 << i);
  }
  if (!f(pos))
    cout << "Lillebror" << endl;
  else
    cout << "Karlsson" << endl;
  return 0;
}
