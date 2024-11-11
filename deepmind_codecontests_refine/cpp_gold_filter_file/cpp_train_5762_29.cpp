#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
void mytimer(string task) {}
void ext(int c) {}
char src[2100][2100];
char ar1[2100][2100];
char ar2[2100][2100];
int n;
const int A = 5;
vector<pair<int, int> > fig;
void dfs(int a, int b) {
  fig.push_back(make_pair(a, b));
  ar2[a][b] = 2;
  const int da[] = {0, 0, -1, 1};
  const int db[] = {-1, 1, 0, 0};
  for (int i = 0; i < (4); ++i) {
    int aa = a + da[i];
    int bb = b + db[i];
    if (ar2[aa][bb] == 1) dfs(aa, bb);
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (n); ++j) {
      int t;
      scanf("%d", &t);
      src[i + 5][j + 5] = (char)t;
    }
  }
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (n); ++j) {
      int s = 0, c = 0;
      for (int a = 0; a < (9); ++a) {
        for (int b = 0; b < (9); ++b) {
          if (((a - 4) * (a - 4)) + ((b - 4) * (b - 4)) <= ((4) * (4))) {
            if (src[i + 5 + a - 4][j + 5 + b - 4]) ++s;
            ++c;
          }
        }
      }
      ar1[i + 5][j + 5] = s * 2 > c;
    }
  }
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (n); ++j) {
      int s = 0;
      for (int a = 0; a < (7); ++a) {
        for (int b = 0; b < (7); ++b) {
          if (((a - 3) * (a - 3)) + ((b - 3) * (b - 3)) <= ((3) * (3)) &&
              ar1[i + 5 + a - 3][j + 5 + b - 3]) {
            s = 1;
            break;
          }
        }
      }
      ar2[i + 5][j + 5] = !!s;
    }
  }
  int rec = 0, cir = 0;
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (n); ++j) {
      if (ar2[i + 5][j + 5] == 1) {
        fig.clear();
        dfs(i + 5, j + 5);
        double a = 0, b = 0;
        for (int k = 0; k < (int)fig.size(); ++k) {
          a += fig[k].first;
          b += fig[k].second;
        }
        a /= fig.size();
        b /= fig.size();
        double mind = 1e200, maxd = -1e200;
        for (int k = 0; k < (int)fig.size(); ++k) {
          int aa = fig[k].first;
          int bb = fig[k].second;
          if (!ar2[aa + 1][bb] || !ar2[aa - 1][bb] || !ar2[aa][bb + 1] ||
              !ar2[aa][bb - 1]) {
            double d = ((fig[k].first - a) * (fig[k].first - a)) +
                       ((fig[k].second - b) * (fig[k].second - b));
            if (d < mind) mind = d;
            if (d > maxd) maxd = d;
          }
        }
        if (maxd / mind > 1.4)
          ++rec;
        else
          ++cir;
        cerr << maxd / mind << endl;
      }
    }
  }
  cout << cir << ' ' << rec;
  return 0;
}
