#include <bits/stdc++.h>
using namespace std;
int a[1700][1700], vst[1700][1700], cnt[1700 * 10], tvst[1700][1700], R, C,
    VST[1700][1700];
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
vector<pair<int, int> > vec[1700 * 10];
int id;
int main() {
  int ct, rrr[100], ccc[100], t, i, j, k, flag, r, d, c, rr, cc, tflag = 0,
                                                                 FLAG = 0;
  scanf("%d%d", &R, &C);
  memset(vst, 0, sizeof(vst));
  memset(tvst, 0, sizeof(tvst));
  memset(VST, 0, sizeof(VST));
  for (i = 0; i < R; i++)
    for (j = 0; j < C; j++) scanf("%d", &a[i][j]);
  flag = 0;
  for (i = 0; i < R; i++) {
    for (j = 0; j < C; j++) {
      if (a[i][j] == 0) continue;
      if (vst[i][j]) continue;
      flag++;
      vst[i][j] = flag;
      queue<int> q = queue<int>();
      q.push(i);
      q.push(j);
      while (!q.empty()) {
        r = q.front();
        q.pop();
        c = q.front();
        q.pop();
        for (k = 0; k < 4; k++) {
          rr = r + dr[k];
          cc = c + dc[k];
          if ((rr < 0 || cc < 0 || rr >= R || cc >= C)) continue;
          if (a[rr][cc] == 0) continue;
          if (vst[rr][cc]) continue;
          vst[rr][cc] = flag;
          q.push(rr);
          q.push(cc);
        }
      }
    }
  }
  printf("%d\n", flag);
  for (i = 1; i <= flag; i++) {
    vec[i].clear();
  }
  for (i = 0; i < R; i++)
    for (j = 0; j < C; j++) {
      if (a[i][j] == 0) continue;
      for (k = 0; k < 4; k++) {
        r = i + dr[k];
        c = j + dc[k];
        if ((r < 0 || c < 0 || r >= R || c >= C) || a[r][c] == 0) break;
      }
      if (k < 4) vec[vst[i][j]].push_back(pair<int, int>(i, j));
    }
  FLAG = tflag = 0;
  for (i = 1; i <= flag; i++) {
    cnt[i] = 0;
    FLAG++;
    for (j = 0; j < vec[i].size(); j++) {
      r = vec[i][j].first;
      c = vec[i][j].second;
      if (VST[r][c] == FLAG) continue;
      queue<int> q = queue<int>();
      tflag++;
      q.push(r);
      q.push(c);
      q.push(0);
      ct = 0;
      rrr[ct] = r;
      ccc[ct++] = c;
      tvst[r][c] = tflag;
      while (ct < 100 && !q.empty()) {
        r = q.front();
        q.pop();
        c = q.front();
        q.pop();
        d = q.front();
        q.pop();
        if (d == 10) continue;
        for (k = 0; ct < 100 && k < 4; k++) {
          rr = r + dr[k];
          cc = c + dc[k];
          if ((rr < 0 || cc < 0 || rr >= R || cc >= C)) continue;
          if (vst[rr][cc] != i) continue;
          if (tvst[rr][cc] == tflag) continue;
          tvst[rr][cc] = tflag;
          q.push(rr);
          q.push(cc);
          q.push(d + 1);
          rrr[ct] = rr;
          ccc[ct++] = cc;
        }
      }
      if (ct < 3 * 10 + 10) {
        cnt[i]++;
        for (k = 0; k < ct; k++) {
          VST[rrr[k]][ccc[k]] = FLAG;
        }
      }
    }
  }
  sort(cnt + 1, cnt + flag + 1);
  for (i = 1; i <= flag; i++) printf("%d ", cnt[i]);
  puts("");
  return 0;
}
