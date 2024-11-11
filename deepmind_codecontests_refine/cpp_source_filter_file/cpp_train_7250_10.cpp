#include <bits/stdc++.h>
using namespace std;
bool debug = false;
int n;
int best = 1e9;
vector<pair<int, pair<int, int>>> path;
vector<pair<int, pair<int, int>>> bP;
bitset<256> made;
void dfs(int cost) {
  if (made[n]) {
    if (cost < best) {
      best = cost;
      bP = path;
    }
    return;
  }
  if (cost >= best) {
    return;
  }
  if (cost >= 5) {
    return;
  }
  for (int i = 0; i <= 255; i++) {
    if (made[i]) {
      for (int j = 0; j <= 255; j++) {
        if (made[j]) {
          for (int k = 1; k <= 8; k <<= 1) {
            int nw = i + k * j;
            if (nw <= 255 && !made[nw]) {
              made[nw] = true;
              path.push_back(make_pair(i, make_pair(j, k)));
              dfs(cost + 1);
              made[nw] = false;
              path.pop_back();
            }
          }
        }
      }
    }
  }
}
int reg[256];
int regC;
char getReg(int no) {
  if (no == 1) {
    return 'a';
  }
  if (reg[no] != 0) {
    return reg[no] + 'a';
  }
  regC++;
  reg[no] = regC;
  return getReg(no);
}
int main(int argc, char* argv[]) {
  cin >> n;
  made[1] = 1;
  made[0] = 1;
  dfs(0);
  cout << best << endl;
  for (pair<int, pair<int, int>> p : bP) {
    int to = p.first + p.second.first * p.second.second;
    printf("lea e%cx [", getReg(to));
    if (p.first != 0) {
      printf("e%cx + ", getReg(p.first));
    }
    printf("%d*e%cx]\n", p.second.second, getReg(p.second.first));
  }
  return 0;
}
