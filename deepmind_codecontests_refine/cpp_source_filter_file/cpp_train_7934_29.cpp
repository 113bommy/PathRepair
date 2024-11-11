#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::queue;
using std::stable_sort;
using std::string;
using std::vector;
using namespace std;
const int MaxN = 55;
char ch[8][8];
int mas[MaxN];
int win[MaxN];
vector<pair<int, pair<int, int>>> vect2[MaxN][MaxN][MaxN];
int answer = 1;
bool endd = false;
char mass[15][15][15];
bool used[15][15][15];
void dfs(int in, int ij, int ik) {
  if (endd == true) return;
  if (ik == 9) {
    endd = true;
    return;
  }
  if (ch[in - ik - 1][ij] != 'S') dfs(in, ij, ik + 1);
  if (in < 7) dfs(in + 1, ij, ik + 1);
  if (in > 0 && (in - ik - 1 < 0 || ch[in - ik - 1][ij] != 'S') &&
      (in - ik - 2 <= 0 || ch[in - ik - 2][ij] != 'S'))
    dfs(in - 1, ij, ik + 1);
  if (ij > 0 && (in - ik < 0 || ch[in - ik][ij - 1] != 'S') &&
      (in - ik - 1 <= 0 || ch[in - ik - 1][ij - 1] != 'S'))
    dfs(in, ij - 1, ik + 1);
  if (ij < 7 && (in - ik < 0 || ch[in - ik][ij + 1] != 'S') &&
      (in - ik - 1 <= 0 || ch[in - ik - 1][ij + 1] != 'S'))
    dfs(in, ij + 1, ik + 1);
  if (ij < 7 && in < 7 && (in - ik < 0 || ch[in - ik][ij + 1] != 'S') &&
      (in - ik <= 0 || ch[in - ik + 1][ij + 1] != 'S'))
    dfs(in + 1, ij + 1, ik + 1);
  if (ij < 7 && in > 0 && (in - ik - 1 < 0 || ch[in - ik - 1][ij + 1] != 'S') &&
      (in - ik - 2 <= 0 || ch[in - ik - 2][ij + 1] != 'S'))
    dfs(in - 1, ij + 1, ik + 1);
  if (ij > 0 && in < 7 && (in - ik < 0 || ch[in - ik][ij - 1] != 'S') &&
      (in - ik <= 0 || ch[in - ik + 1][ij - 1] != 'S'))
    dfs(in + 1, ij - 1, ik + 1);
  if (ij > 0 && in > 0 && (in - ik - 1 < 0 || ch[in - ik - 1][ij - 1] != 'S') &&
      (in - ik - 2 <= 0 || ch[in - ik - 2][ij - 1] != 'S'))
    dfs(in - 1, ij - 1, ik + 1);
}
int main() {
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) {
      cin >> ch[i][j];
    }
  dfs(7, 0, 0);
  if (endd == false)
    cout << "LOSE";
  else
    cout << "WIN";
  return 0;
}
