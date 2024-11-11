#include <bits/stdc++.h>
using namespace std;
int vert[256][256];
int horz[256][256];
char line[5][10000];
char s[1000];
long long dp[256];
long long l[256];
bool allvert[256];
const long long MOD = (int)1e9 + 7;
int main(int argc, char* argv[]) {
  gets(s);
  int N, M;
  sscanf(s, "%d %d", &N, &M);
  set<string> canVert;
  set<string> canHorz;
  canHorz.insert(
      "..."
      "..."
      "...");
  canHorz.insert(
      "..."
      ".O."
      "...");
  canHorz.insert(
      "O.."
      "..."
      "..O");
  canHorz.insert(
      "O.."
      ".O."
      "..O");
  canHorz.insert(
      "O.O"
      "..."
      "O.O");
  canHorz.insert(
      "O.O"
      ".O."
      "O.O");
  canHorz.insert(
      "OOO"
      "..."
      "OOO");
  canVert.insert(
      "..."
      "..."
      "...");
  canVert.insert(
      "..."
      ".O."
      "...");
  canVert.insert(
      "..O"
      "..."
      "O..");
  canVert.insert(
      "..O"
      ".O."
      "O..");
  canVert.insert(
      "O.O"
      "..."
      "O.O");
  canVert.insert(
      "O.O"
      ".O."
      "O.O");
  canVert.insert(
      "O.O"
      "O.O"
      "O.O");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 4; j++) gets(line[j]);
    for (int j = 0; j < M; j++) {
      string s;
      for (int ii = 1; ii < 4; ii++) {
        for (int jj = 1; jj < 4; jj++) {
          s += line[ii][j * 4 + jj];
        }
      }
      if (canVert.find(s) != canVert.end()) {
        vert[i][j] = 1;
      }
      if (canHorz.find(s) != canHorz.end()) {
        horz[i][j] = 1;
      }
    }
  }
  for (int j = 0; j < M; j++) {
    allvert[j] = N % 2 == 0;
    for (int i = 0; i < N; i++) {
      if (!vert[i][j]) {
        allvert[j] = false;
        break;
      }
    }
  }
  dp[0] = 1;
  for (int j = 0; j < M; j++) {
    if (allvert[j]) {
      dp[j + 1] = (dp[j + 1] + dp[j]) % MOD;
    }
    if (j + 1 < M) {
      memset(l, 0, sizeof(l));
      l[0] = 1;
      for (int i = 0; i < N; i++) {
        if (horz[i][j] && horz[i][j + 1]) {
          l[i + 1] = (l[i + 1] + l[i]) % MOD;
        }
        if (i + 1 < N) {
          if (vert[i][j] && vert[i][j + 1] && vert[i + 1][j] &&
              vert[i + 1][j + 1])
            l[i + 2] = (l[i + 2] + l[i]) % MOD;
        }
      }
      long long total = l[N];
      if (allvert[j] && allvert[j + 1]) total--;
      dp[j + 2] = (dp[j + 2] + dp[j] * total) % MOD;
    }
  }
  printf("%d\n", (int)(dp[M] + MOD) % MOD);
  return 0;
}
