#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> nr;
bool drept(vector<pair<int, int>> v);
bool patrat(vector<pair<int, int>> v);
bool edrept(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
bool epatrat(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
int distanta(int x1, int y1, int x2, int y2);
bool perpendicular(int x1, int y1, int x2, int y2, int x3, int y3);
int main() {
  for (int i = 0; i < 8; i++) {
    int a, b;
    cin >> a >> b;
    nr.push_back({a, b});
  }
  int st[10];
  for (int i = 0; i < (1 << 9); i++) {
    vector<pair<int, int>> drp, ptr;
    int n = i;
    for (int j = 0; j < 8; j++) {
      if (n & 1) {
        drp.push_back(nr[j]);
        st[j] = 1;
      } else {
        ptr.push_back(nr[j]);
        st[j] = 2;
      }
      n /= 2;
    }
    if (drp.size() != 4) continue;
    if (drept(drp) && patrat(ptr)) {
      cout << "YES\n";
      for (int j = 0; j < 8; j++) {
        if (st[j] == 2) cout << j + 1 << ' ';
      }
      cout << '\n';
      for (int j = 0; j < 8; j++) {
        if (st[j] == 1) cout << j + 1 << ' ';
      }
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
bool drept(vector<pair<int, int>> v) {
  for (int i = 1; i < 4; i++) {
    for (int j = 1; j < 4; j++) {
      for (int k = 1; k < 4; k++) {
        if (i == j || i == k || j == k) continue;
        if (edrept(v[0].first, v[0].second, v[i].first, v[i].second, v[j].first,
                   v[j].second, v[k].first, v[k].second))
          return true;
      }
    }
  }
  return false;
}
bool patrat(vector<pair<int, int>> v) {
  for (int i = 1; i < 4; i++) {
    for (int j = 1; j < 4; j++) {
      for (int k = 1; k < 4; k++) {
        if (i == j || i == k || j == k) continue;
        if (epatrat(v[0].first, v[0].second, v[i].first, v[i].second,
                    v[j].first, v[j].second, v[k].first, v[k].second))
          return true;
      }
    }
  }
  return false;
}
bool edrept(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  if (distanta(x1, y1, x2, y2) != distanta(x3, y3, x4, y4) ||
      distanta(x2, y2, x3, y3) != distanta(x4, y4, x1, y1))
    return false;
  if (perpendicular(x1, y1, x2, y2, x3, y3)) return true;
  return false;
}
bool epatrat(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  int dst = distanta(x1, y1, x2, y2);
  if (dst != distanta(x3, y3, x4, y4) || dst != distanta(x2, y2, x3, y3) ||
      dst != distanta(x4, y4, x1, y1))
    return false;
  if (perpendicular(x1, y1, x2, y2, x3, y3)) return true;
  return false;
}
int distanta(int x1, int y1, int x2, int y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
bool perpendicular(int x1, int y1, int x2, int y2, int x3, int y3) {
  if ((x1 - x2) * (x3 - x2) + (y1 - y2) * (y3 - y2) == 0) return true;
  return false;
}
