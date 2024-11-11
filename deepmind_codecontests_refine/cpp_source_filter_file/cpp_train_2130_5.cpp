#include <bits/stdc++.h>
using namespace std;
int in[8][3];
long long dist2(int *a, int *b) {
  long long res = 0;
  for (int i = 0; i < 3; i++) {
    res += 1LL * (a[i] - b[i]) * (a[i] - b[i]);
  }
  return res;
}
long long dot(long long x1, long long y1, long long z1, long long x2,
              long long y2, long long z2) {
  return x1 * x2 + y1 * y2 + z1 * z2;
}
pair<long long, int> v[8];
bool good() {
  long long len = -1;
  for (int f = 0; f < 4; f++) {
    int cc = 0;
    for (int i = 0; i < 8; i++) {
      if (i == f) continue;
      v[cc] = pair<long long, int>(dist2(in[f], in[i]), i);
      cc++;
    }
    sort(v, v + 7);
    if (v[0].first != v[1].first || v[0].first != v[2].first ||
        v[1].first != v[2].first)
      return false;
    if (len != -1 && len != v[0].first) return false;
    if (v[0].first == 0) return false;
    for (int i = 0; i < 3; i++) {
      for (int j = i + 1; j < 3; j++) {
        int id1 = v[i].second;
        int id2 = v[j].second;
        if (dot(in[id2][0] - in[f][0], in[id2][1] - in[f][1],
                in[id2][2] - in[f][2], in[id1][0] - in[f][0],
                in[id1][1] - in[f][1], in[id1][2] - in[f][2])) {
          return false;
        }
      }
    }
  }
  return true;
}
int cnt = 0;
void search(int at) {
  if (at == 8) {
    if (good()) {
      printf("YES\n");
      for (int i = 0; i < 8; i++) {
        printf("%d", in[i][0]);
        for (int j = 1; j < 3; j++) printf(" %d", in[i][j]);
        printf("\n");
      }
      exit(0);
    }
  } else {
    do {
      search(at + 1);
    } while (next_permutation(in[at], in[at] + 3));
  }
}
int main() {
  for (int i = 0; i < 8; i++) {
    scanf("%d %d %d", &in[i][0], &in[i][1], &in[i][2]);
    sort(in[i], in[i] + 3);
  }
  search(0);
  printf("NO\n");
  return 0;
}
