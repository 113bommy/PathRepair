#include <bits/stdc++.h>
using namespace std;
int t, x[5], y[5];
int ans_x[5], ans_y[5];
set<int> d, xb, yb;
set<int>::iterator it1, it2, it3;
int best = INT_MAX;
void reset() {
  best = INT_MAX;
  d.clear();
}
void pro(int bx, int by, int s) {
  vector<int> temp;
  for (int i = 1; i <= 4; i++) temp.push_back(i);
  do {
    bool pos = true;
    int mov = INT_MIN;
    for (int i = 0; i <= 1; i++) {
      if (!pos) break;
      for (int j = 0; j <= 1; j++) {
        int ind = 2 * i + j;
        int dx = x[temp[ind]] - (bx + i * s), dy = y[temp[ind]] - (by + j * s);
        if (dx == 0 || dy == 0) {
          mov = max(mov, abs(dx + dy));
        } else {
          pos = false;
          break;
        }
      }
    }
    if (pos) {
      if (mov < best) {
        best = mov;
        for (int i = 0; i <= 1; i++) {
          for (int j = 0; j <= 1; j++) {
            int ind = 2 * i + j;
            ans_x[temp[ind]] = (bx + i * s);
            ans_y[temp[ind]] = (by + j * s);
          }
        }
      }
    }
  } while (next_permutation(temp.begin(), temp.end()));
}
void pro(int s) {
  vector<int> temp;
  for (int i = 1; i <= 4; i++) temp.push_back(i);
  do {
    vector<int> tx, ty;
    for (int i = 0; i <= 1; i++) {
      for (int j = 0; j <= 1; j++) {
        int ind = 2 * i + j;
        int xx = x[temp[ind]] - i * s, yy = y[temp[ind]] - j * s;
        tx.push_back(xx);
        ty.push_back(yy);
      }
    }
    bool xeq = true, yeq = true;
    for (int j = 1; j <= tx.size() - 1; j++) {
      if (tx[j] != tx[0]) {
        xeq = false;
        break;
      }
    }
    for (int j = 1; j <= ty.size() - 1; j++) {
      if (ty[j] != ty[0]) {
        yeq = false;
        break;
      }
    }
    int MIN = INT_MAX, MAX = INT_MIN;
    if (xeq || yeq) {
      int mov = INT_MIN;
      if (xeq) {
        for (int j = 0; j < ty.size(); j++) {
          MIN = min(MIN, ty[j]);
          MAX = max(MAX, ty[j]);
        }
      } else if (yeq) {
        for (int j = 0; j < tx.size(); j++) {
          MIN = min(MIN, tx[j]);
          MAX = max(MAX, tx[j]);
        }
      }
      mov = (MAX - MIN + 1) / 2;
      int dispX[5], dispY[5];
      memset(dispX, 0, sizeof(dispX));
      memset(dispY, 0, sizeof(dispY));
      int movTo = (MAX + MIN) / 2;
      if (xeq) {
        for (int j = 0; j < ty.size(); j++) {
          dispY[temp[j]] += movTo - ty[j];
        }
      } else if (yeq) {
        for (int j = 0; j < tx.size(); j++) {
          dispX[temp[j]] += movTo - tx[j];
        }
      }
      if (mov < best) {
        best = mov;
        for (int i = 0; i <= 1; i++) {
          for (int j = 0; j <= 1; j++) {
            int ind = 2 * i + j;
            ans_x[temp[ind]] = x[temp[ind]] + dispX[temp[ind]];
            ans_y[temp[ind]] = y[temp[ind]] + dispY[temp[ind]];
          }
        }
      }
    }
  } while (next_permutation(temp.begin(), temp.end()));
}
int main() {
  ios_base::sync_with_stdio(false);
  int precision = numeric_limits<long double>::digits10;
  cin >> t;
  for (int q = 1; q <= t; q++) {
    for (int i = 1; i <= 4; i++) {
      cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= 4; i++) {
      for (int j = i + 1; j <= 4; j++) {
        int dis = abs(x[i] - x[j]);
        if (dis != 0) d.insert(dis);
        dis = abs(y[i] - y[j]);
        if (dis != 0) d.insert(dis);
      }
    }
    for (it1 = d.begin(); it1 != d.end(); it1++) {
      int pos = *it1;
      xb.clear();
      yb.clear();
      for (int i = 1; i <= 4; i++) {
        xb.insert(x[i] - pos);
        xb.insert(x[i]);
        xb.insert(x[i] + pos);
        yb.insert(y[i] - pos);
        yb.insert(y[i]);
        yb.insert(y[i] + pos);
      }
      for (it2 = xb.begin(); it2 != xb.end(); it2++) {
        for (it3 = yb.begin(); it3 != yb.end(); it3++) {
          pro(*it2, *it3, *it1);
        }
      }
      pro(*it1);
    }
    if (best == INT_MAX)
      cout << -1 << "\n";
    else {
      cout << best << "\n";
      for (int i = 1; i <= 4; i++) cout << ans_x[i] << " " << ans_y[i] << "\n";
    }
    reset();
  }
}
