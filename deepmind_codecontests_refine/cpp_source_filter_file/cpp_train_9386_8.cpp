#include <bits/stdc++.h>
using namespace std;
int n;
struct Rect {
  int x1, x2, y1, y2;
  Rect(int x1 = 0, int x2 = 0, int y1 = 0, int y2 = 0)
      : x1(x1), x2(x2), y1(y1), y2(y2) {}
};
vector<Rect> V;
queue<vector<Rect> > Q;
bool spilt(vector<Rect>& v) {
  vector<int> Xrow, Yrow;
  int l = v.size();
  int u;
  for (int i = 0; i < l; i++) {
    Xrow.push_back(v[i].x1);
    Yrow.push_back(v[i].y1);
  }
  sort(Xrow.begin(), Xrow.end());
  u = unique(Xrow.begin(), Xrow.end()) - Xrow.begin();
  for (int i = 1; i < u; i++) {
    int x = Xrow[i];
    bool flag = false;
    for (int j = 0; j < v.size(); j++) {
      if ((v[j].x2 <= x) || (v[j].x1 >= x))
        continue;
      else {
        flag = false;
      }
    }
    if (!flag) {
      vector<Rect> V1;
      vector<Rect> V2;
      for (int j = 0; j < v.size(); j++) {
        if (v[j].x2 <= x)
          V1.push_back(v[j]);
        else
          V2.push_back(v[j]);
      }
      Q.push(V1);
      Q.push(V2);
      return true;
    }
  }
  sort(Yrow.begin(), Yrow.end());
  u = unique(Yrow.begin(), Yrow.end()) - Yrow.begin();
  for (int i = 1; i < u; i++) {
    int y = Yrow[i];
    bool flag = false;
    for (int j = 0; j < v.size(); j++) {
      if (v[j].y2 <= y || v[j].y1 >= y)
        continue;
      else {
        flag = false;
      }
    }
    if (!flag) {
      vector<Rect> V1;
      vector<Rect> V2;
      for (int j = 0; j < v.size(); j++) {
        if (v[j].y2 <= y)
          V1.push_back(v[j]);
        else
          V2.push_back(v[j]);
      }
      Q.push(V1);
      Q.push(V2);
      return true;
    }
  }
  return false;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    V.push_back(Rect(x1, x2, y1, y2));
  }
  Q.push(V);
  while (!Q.empty()) {
    vector<Rect> X = Q.front();
    Q.pop();
    if (X.size() == 1) continue;
    if (!spilt(X)) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
}
