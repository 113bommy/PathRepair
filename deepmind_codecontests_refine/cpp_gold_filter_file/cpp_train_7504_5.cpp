#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
const int INF = 0x3f3f3f3f;
int n;
string seq1, seq2;
int r1, c1, r2, c2;
int r0, c0;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dist() { return abs(r1 - r2) + abs(c1 - c2); }
int main() {
  scanf("%d", &n);
  r1 = 1, c1 = 1;
  r2 = n, c2 = n;
  while (dist() > n - 1) {
    int xx = r1 + dx[0];
    int yy = c1 + dy[0];
    printf("? %d %d %d %d\n", xx, yy, r2, c2);
    fflush(stdout);
    char rep[5];
    scanf("%s", rep);
    if (rep[0] == 'Y') {
      seq1.push_back('R');
      r1 = xx, c1 = yy;
    } else {
      seq1.push_back('D');
      r1 = r1 + dx[1];
      c1 = c1 + dy[1];
    }
  }
  r0 = r1, c0 = c1;
  r1 = 1, c1 = 1;
  while (dist() > n - 1) {
    int xx = r2 + dx[3];
    int yy = c2 + dy[3];
    if (xx >= r0 && yy >= c0) {
      printf("? %d %d %d %d\n", r1, c1, xx, yy);
      fflush(stdout);
      char rep[5];
      scanf("%s", rep);
      if (rep[0] == 'Y') {
        seq2.push_back('D');
        r2 = xx, c2 = yy;
      } else {
        seq2.push_back('R');
        r2 = r2 + dx[2];
        c2 = c2 + dy[2];
      }
    } else {
      seq2.push_back('R');
      r2 = r2 + dx[2];
      c2 = c2 + dy[2];
    }
  }
  printf("! ");
  reverse(seq2.begin(), seq2.end());
  for (int i = 0; i < seq1.size(); i++) printf("%c", seq1[i]);
  for (int i = 0; i < seq2.size(); i++) printf("%c", seq2[i]);
  puts("");
  fflush(stdout);
  return 0;
}
