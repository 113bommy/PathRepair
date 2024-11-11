#include <bits/stdc++.h>
using namespace std;
vector<int> adj[400000];
int maxnum[19][400000];
int jump[19][400000];
int par[400000];
int dep[400000];
int wes[400000];
int next[400000];
int leap[19][400000];
long long sum[19][400000];
int Q;
int cnt = 1;
int srch(int no, int wei) {
  int cc = no;
  for (int jj = 18; jj >= 0; jj--) {
    if (wes[cc] >= wei) break;
    if (jump[jj][cc] != -1 && maxnum[jj][cc] < wei) {
      cc = jump[jj][cc];
    }
  }
  if (wes[cc] < wei)
    return -1;
  else
    return cc;
}
void add_node(int p, int wei) {
  par[cnt] = p;
  dep[cnt] = dep[p] + 1;
  adj[p].push_back(cnt);
  adj[cnt].push_back(wei);
  wes[cnt] = wei;
  jump[0][cnt] = p;
  maxnum[0][cnt] = wei;
  for (int j = 1; j < 19; j++) {
    if (jump[j - 1][cnt] != -1) {
      jump[j][cnt] = jump[j - 1][jump[j - 1][cnt]];
      maxnum[j][cnt] = max(maxnum[j - 1][cnt], maxnum[j - 1][jump[j - 1][cnt]]);
    } else
      jump[j][cnt] = -1;
  }
  int nxt = srch(par[cnt], wei);
  leap[0][cnt] = nxt;
  sum[0][cnt] = wei;
  for (int j = 1; j < 19; j++) {
    if (leap[j - 1][cnt] == -1) continue;
    leap[j][cnt] = leap[j - 1][leap[j - 1][cnt]];
    sum[j][cnt] = sum[j - 1][cnt] + sum[j - 1][leap[j - 1][cnt]];
  }
  cnt++;
}
int query(int R, long long X) {
  long long csum = 0;
  int cc = R;
  int len = 0;
  for (int j = 18; j >= 0; j--) {
    if (leap[j][cc] != -1 && csum + sum[j][cc] <= X) {
      csum += sum[j][cc];
      cc = leap[j][cc];
      len += (1 << j);
    }
  }
  if (leap[0][cc] == -1 && csum + wes[cc] <= X) {
    csum += wes[cc];
    len++;
  }
  return len;
}
int main() {
  scanf("%d", &Q);
  for (int i = 0; i < (19); ++i)
    for (int j = 0; j < (400000); ++j) {
      jump[i][j] = -1;
      leap[i][j] = -1;
    }
  maxnum[0][0] = 0, sum[0][0] = 0;
  dep[0] = 0;
  int last = 0;
  for (int quer = 0; quer < (Q); ++quer) {
    int ty;
    long long p, q;
    scanf("%d %lld %lld", &ty, &p, &q);
    if (ty == 1) {
      int R = p ^ last;
      int W = q ^ last;
      R--;
      add_node(R, W);
    } else {
      int R = p ^ last;
      R--;
      long long X = q ^ last;
      last = query(R, X);
      printf("%d", last);
    }
  }
}
