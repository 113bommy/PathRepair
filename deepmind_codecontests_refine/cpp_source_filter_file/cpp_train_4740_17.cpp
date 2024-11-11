#include <bits/stdc++.h>
using namespace std;
vector<pair<int, pair<int, int> > > data;
int ii, jj, kk, l;
pair<int, int> bc(int x) {
  int q[4];
  for (int i = 0; i < 4; i++) {
    q[i] = x % 10;
    x /= 10;
  }
  int vis[10];
  memset(vis, 0, sizeof vis);
  vis[ii] = vis[jj] = vis[kk] = vis[l] = 1;
  int b = 0;
  int c = 0;
  if (q[0] == ii)
    b++;
  else if (vis[q[0]] == 1)
    c++;
  if (q[1] == jj)
    b++;
  else if (vis[q[1]] == 1)
    c++;
  if (q[2] == kk)
    b++;
  else if (vis[q[2]] == 1)
    c++;
  if (q[3] == l)
    b++;
  else if (vis[q[3]] == 1)
    c++;
  return make_pair(b, c);
}
int con() {
  int ret = l;
  ret = ret * 10 + kk;
  ret = ret * 10 + jj;
  ret = ret * 10 + ii;
  return ret;
}
int main() {
  int n;
  scanf("%d", &n);
  int x, y, z;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);
    data.push_back(make_pair(x, make_pair(y, z)));
  }
  int flag = 0;
  int val;
  int vis[10];
  for (ii = 0; ii < 10; ii++) {
    for (jj = 0; jj < 10; jj++) {
      for (kk = 0; kk < 10; kk++) {
        for (l = 0; l < 10; l++) {
          memset(vis, 0, sizeof vis);
          vis[ii]++;
          vis[jj]++;
          vis[kk]++;
          vis[l]++;
          int shit = 0;
          for (int i = 0; i < 10; i++) {
            if (vis[i] > 1) {
              shit = 1;
              break;
            }
          }
          if (shit) continue;
          int i;
          for (i = 0; i < n; i++) {
            pair<int, int> ret = bc(data[i].first);
            if (ret != data[i].second) break;
          }
          if (i == n) {
            flag++;
            val = con();
          }
        }
      }
    }
  }
  if (flag == 1) {
    vector<int> stud;
    for (int i = 0; i < 4; i++) {
      stud.push_back(val % 10);
      val /= 10;
    }
    for (int i = 3; i >= 0; i--) cout << stud[i] << endl;
  } else if (flag == 0) {
    cout << "Incorrect data\n";
  } else
    cout << "Need more data\n";
}
