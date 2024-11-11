#include <bits/stdc++.h>
using namespace std;
pair<int, int> paso(pair<int, int> pos, char dir) {
  if (dir == 'U')
    pos.first++;
  else if (dir == 'D')
    pos.first--;
  else if (dir == 'R')
    pos.second++;
  else
    pos.second--;
  return pos;
}
int main() {
  pair<int, int> fin, pos, bl = pair<int, int>(0, 0);
  int K;
  int a, b;
  string S;
  cin >> fin.second >> fin.first >> S;
  for (int i = 0; i < S.size(); i++) {
    bl = paso(bl, S[i]);
  }
  for (int w = 0; w < S.size(); w++) {
    pair<int, int> rd = pair<int, int>(0, 0);
    for (int i = 0; i < w; i++) {
      rd = paso(rd, S[i]);
    }
    rd.first = fin.first - rd.first;
    rd.second = fin.second - rd.second;
    K = min((bl.first != 0) ? fin.first / bl.first : (1 << 30),
            (bl.second != 0) ? fin.second / bl.second : (1 << 30));
    K %= (1 << 30);
    if (K < 0) {
      continue;
    }
    pos = pair<int, int>(K * bl.first, K * bl.second);
    if (pos == rd) {
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");
  return 0;
}
