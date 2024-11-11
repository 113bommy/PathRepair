#include <bits/stdc++.h>
using namespace std;
vector<int> G[33];
char s[100005];
int mark[33];
int main() {
  scanf("%s", &s);
  int large = strlen(s), pos = 0;
  for (int p = (0); p <= (large - 1); p += (1)) G[s[p] - 'a'].push_back(p);
  for (int p = (25); p >= (0); p -= (1)) {
    int cnt = G[p].size();
    if (cnt > 0) {
      for (int q = (0); q <= (cnt - 1); q += (1))
        if (G[p][q] >= pos) {
          pos = G[p][q];
          printf("%c", p + 'a');
        }
    }
  }
}
