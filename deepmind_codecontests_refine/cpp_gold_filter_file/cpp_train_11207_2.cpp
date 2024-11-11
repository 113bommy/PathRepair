#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846264338327950288;
int in_c() {
  int c;
  while ((c = getchar()) <= ' ') {
    if (!~c) return ~0;
  }
  return c;
}
int in() {
  int x = 0, c;
  while ((unsigned int)((c = getchar()) - '0') >= 10) {
    if (c == '-') return -in();
    if (!~c) return ~0;
  }
  do {
    x = 10 * x + (c - '0');
  } while ((unsigned int)((c = getchar()) - '0') < 10);
  return x;
}
int N, W, M;
int main() {
  int N, W, M;
  while (cin >> N >> W >> M) {
    bool ok = true;
    vector<vector<pair<int, int> > > distribution(M);
    int remain = M, cur_index = 0, cont = 0;
    for (int i = 0, e__ = (M); i < e__; ++i) {
      int get = 0;
      while (get < N) {
        if (remain == 0) {
          ++cur_index;
          if (cur_index == N) {
            ok = false;
            goto END;
          }
          remain += M;
          cont = 0;
        } else if (remain > N - get) {
          distribution[i].push_back(make_pair(cur_index, N - get));
          remain -= N - get;
          get = N;
          ++cont;
          if (cont == 3) {
            ok = false;
            goto END;
          }
        } else {
          distribution[i].push_back(make_pair(cur_index, remain));
          get += remain;
          remain = 0;
          ++cont;
          if (cont == 3) {
            ok = false;
            goto END;
          }
        }
      }
    }
  END:;
    if (ok) {
      cout << "YES" << endl;
      for (int i = 0, e__ = (M); i < e__; ++i) {
        for (int j = 0, e__ = (distribution[i].size() - 1); j < e__; ++j)
          printf("%d %.6f ", distribution[i][j].first + 1,
                 (double)(distribution[i][j].second) * W / M);
        printf("%d %.6f\n", distribution[i].back().first + 1,
               (double)(distribution[i].back().second) * W / M);
      }
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
