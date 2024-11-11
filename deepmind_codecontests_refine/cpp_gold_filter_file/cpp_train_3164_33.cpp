#include <bits/stdc++.h>
using namespace std;
class Item {
 public:
  int a, num;
  bool operator<(const Item& other) const { return a < other.a; }
};
int h, w, k;
char hor[1000][1000], ver[1000][1000];
int a[1000][1000], b[1000][1000];
int N, E;
bool swapped;
inline void setLine(const int& line) {
  a[line][0] = 1;
  for (int(i) = (1); (i) < (w); ++(i))
    a[line][i] =
        (hor[line][i - 1] == 'E') ? a[line][i - 1] : 3 - a[line][i - 1];
}
inline void flipLine(const int& line) {
  for (int(j) = (0); (j) < (w); ++(j)) a[line][j] = 3 - a[line][j];
}
inline void setColumn(const int& col) {
  b[0][col] = 1;
  for (int(j) = (1); (j) < (h); ++(j))
    b[j][col] = (ver[j - 1][col] == 'E') ? b[j - 1][col] : 3 - b[j - 1][col];
}
inline void flipColumn(const int& col) {
  for (int(j) = (0); (j) < (h); ++(j)) b[j][col] = 3 - b[j][col];
}
int main() {
  cin >> h >> w >> k;
  if (k == 1) {
    char s[1000];
    for (int(i) = (0); (i) < ((h << 1) - 1); ++(i)) {
      scanf("%s", s);
      int ln = strlen(s);
      for (int(j) = (0); (j) < (ln); ++(j)) (s[j] == 'E') ? E++ : N++;
    }
    int constr = E + N;
    if (4 * E >= 3 * constr) {
      cout << "YES\n";
      for (int(i) = (0); (i) < (h); ++(i)) {
        for (int(j) = (0); (j) < (w); ++(j)) printf("1 ");
        cout << endl;
      }
    } else {
      cout << "NO\n";
    }
    return 0;
  }
  for (int(i) = (0); (i) < (h); ++(i)) {
    scanf("%s", hor[i]);
    if (i != h - 1) scanf("%s", ver[i]);
  }
  int one = 0, two = 0;
  setLine(0);
  for (int(i) = (1); (i) < (h); ++(i)) {
    setLine(i);
    int bad = 0;
    for (int(j) = (0); (j) < (w); ++(j))
      if ((a[i][j] == a[i - 1][j] && ver[i - 1][j] == 'N') ||
          (a[i][j] != a[i - 1][j] && ver[i - 1][j] == 'E'))
        bad++;
    if (bad * 2 > w) flipLine(i);
    one += min(bad, w - bad);
  }
  setColumn(0);
  for (int(j) = (1); (j) < (w); ++(j)) {
    setColumn(j);
    int bad = 0;
    for (int(i) = (0); (i) < (h); ++(i))
      if ((b[i][j] == b[i][j - 1] && hor[i][j - 1] == 'N') ||
          (b[i][j] != b[i][j - 1] && hor[i][j - 1] == 'E'))
        bad++;
    if (bad * 2 > h) flipColumn(j);
    two += min(bad, h - bad);
  }
  printf("YES\n");
  for (int(i) = (0); (i) < (h); ++(i)) {
    for (int(j) = (0); (j) < (w); ++(j))
      printf("%d ", one < two ? a[i][j] : b[i][j]);
    printf("\n");
  }
}
