#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v;
  v.push_back(0);
  for (int i = 0; i < 3; i++) {
    int y;
    cin >> y;
    v.push_back(y);
  }
  if (v[1] == v[2] && v[2] == v[3]) {
    if (v[1] % 2 == 0) {
      cout << v[1] / 2 << " " << v[2] / 2 << " " << v[3] / 2;
      return 0;
    } else
      cout << "Impossible";
    return 0;
  }
  if (v[3] > v[2] && v[3] > v[1]) {
    int u = (v[2] + v[1]);
    if (v[3] == u) {
      cout << "0 " << v[2] << " " << v[1];
      return 0;
    } else if (v[3] > u) {
      cout << "Impossible";
      return 0;
    } else if (v[3] < u) {
      int o = u - v[3];
      if (o % 2 != 0) {
        cout << "Impossible";
        return 0;
      }
      v[1] -= o / 2;
      v[2] -= o / 2;
      if (v[1] + v[2] == v[3]) {
        cout << o / 2 << " " << v[2] << " " << v[1];
        return 0;
      } else {
        cout << "Impossible";
        return 0;
      }
    }
  } else if (v[2] > v[1] && v[2] > v[3]) {
    int u = (v[3] + v[1]);
    if (v[2] == u) {
      cout << v[1] << v[3] << " "
           << "0 ";
      return 0;
    } else if (v[2] > u) {
      cout << "Impossible";
      return 0;
    } else if (v[2] < u) {
      int o = u - v[2];
      if (o % 2 != 0) {
        cout << "Impossible";
        return 0;
      }
      v[1] -= o / 2;
      v[3] -= o / 2;
      if (v[1] + v[3] == v[2]) {
        cout << v[1] << " " << v[3] << " " << o / 2;
        return 0;
      } else {
        cout << "Impossible";
        return 0;
      }
    }
  } else if (v[1] > v[2] && v[1] > v[3]) {
    int u = (v[3] + v[2]);
    if (v[1] == u) {
      cout << v[2] << " 0 " << v[3];
      return 0;
    } else if (v[1] > u) {
      cout << "Impossible";
      return 0;
    } else if (v[1] < u) {
      int o = u - v[1];
      if (o % 2 != 0 || ((o / 2) > v[2] || (o / 2) > v[1])) {
        cout << "Impossible";
        return 0;
      }
      v[2] -= o / 2;
      v[3] -= o / 2;
      if (v[2] + v[3] == v[1]) {
        cout << v[2] << " " << o / 2 << " " << v[3];
        return 0;
      } else {
        cout << "Impossible";
        return 0;
      }
    }
  }
}
