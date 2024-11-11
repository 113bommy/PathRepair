#include <bits/stdc++.h>
using namespace std;
namespace Work {
const int kMaxSz = 100010;
const int kMaxLim = 555;
int n, m;
map<int, int> id;
int arr[kMaxSz];
int idval[kMaxSz], nid = 0;
int cnt[kMaxSz];
int retid[kMaxLim], nretid = 0;
map<int, int> pos;
int sum[kMaxSz][kMaxLim];
void solve(FILE* fin, FILE* fout) {
  fscanf(fin, "%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    fscanf(fin, "%d", arr + i);
    if (!id.count(arr[i])) {
      id[arr[i]] = ++nid;
      idval[nid] = arr[i];
    }
    int cid = id[arr[i]];
    cnt[cid]++;
  }
  for (int i = 1; i <= nid; i++)
    if (cnt[i] >= idval[i]) {
      retid[nretid++] = i;
      pos[i] = nretid - 1;
    }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < nretid; j++) sum[i][j] += sum[i - 1][j];
    int cid = id[arr[i]];
    if (cnt[cid] >= arr[i]) sum[i][pos[cid]]++;
  }
  for (int i = 0; i < m; i++) {
    int l, r;
    fscanf(fin, "%d%d", &l, &r);
    int ret = 0;
    for (int j = 0; j < nretid; j++)
      ret += ((sum[r][j] - sum[l - 1][j]) == idval[retid[j]]);
    fprintf(fout, "%d\n", ret);
  }
  return;
}
}  // namespace Work
int main() {
  Work::solve(stdin, stdout);
  return 0;
}
