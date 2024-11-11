#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int INF = 2e9;
const long long INFLL = 1e18;
const int MAX_N = 1000;
int T;
int N, X;
vector<int> gp[MAX_N + 1];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &N, &X);
    for (int i = 1; i <= N; i++) {
      while (!gp[i].empty()) gp[i].pop_back();
    }
    for (int i = 1; i < N; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      gp[a].push_back(b);
      gp[b].push_back(a);
    }
    bool tf;
    if (gp[X].size() == 1) {
      tf = true;
    } else {
      if (N % 2) {
        tf = false;
      } else {
        tf = true;
      }
    }
    if (tf) {
      printf("Ayush\n");
    } else {
      printf("Ashish\n");
    }
  }
  return 0;
}
