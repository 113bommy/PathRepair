#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
int x[4], y[4];
int main() {
  std::ios::sync_with_stdio(false);
  int area = 0;
  for (int i = 1; i <= 3; ++i) cin >> x[i] >> y[i], area += x[i] * y[i];
  int side = -1, index;
  for (int i = 1; i <= 3; ++i) {
    if (x[i] >= side) {
      side = x[i];
      index = i;
    }
    if (y[i] >= side) {
      side = y[i];
      index = i;
    }
  }
  if (area != side * side) {
    cout << -1;
    return 0;
  }
  int a, b;
  if (x[index] == side) {
    a = side;
    b = side - y[index];
  } else {
    a = side;
    b = side - x[index];
  }
  vector<pair<int, int> > arr;
  for (int i = 1; i <= 3; ++i) {
    if (i != index) {
      arr.push_back(pair<int, int>(x[i], y[i]));
    }
  }
  int type, xx, yy;
  if (arr[0].first == a || arr[0].second == a) {
    if (arr[1].first == a || arr[1].second == a) {
      if (arr[0].first == a) {
        if (arr[1].first == a) {
          if (arr[0].second + arr[1].second == b) {
            type = 1;
            xx = 1;
            yy = 1;
          } else {
            cout << -1;
            return 0;
          }
        } else if (arr[1].second == a) {
          if (arr[0].second + arr[1].first == b) {
            type = 1;
            xx = 1;
            yy = 0;
          } else {
            cout << -1;
            return 0;
          }
        } else
          assert(0);
      } else {
        if (arr[1].first == a) {
          if (arr[0].first + arr[1].second == b) {
            type = 1;
            xx = 0;
            yy = 1;
          } else {
            cout << -1;
            return 0;
          }
        } else if (arr[1].second == a) {
          if (arr[0].first + arr[1].first == b) {
            type = 1;
            xx = 0;
            yy = 0;
          } else {
            cout << -1;
            return 0;
          }
        } else
          assert(0);
      }
    } else {
      cout << -1;
      return 0;
    }
  } else if (arr[0].first == b || arr[0].second == b) {
    if (arr[1].first == b || arr[1].second == b) {
      if (arr[0].first == b) {
        if (arr[1].first == b) {
          if (arr[0].second + arr[1].second == a) {
            type = 2;
            xx = 1;
            yy = 1;
          } else {
            cout << -1;
            return 0;
          }
        } else if (arr[1].second == b) {
          if (arr[0].second + arr[1].first == a) {
            type = 2;
            xx = 1;
            yy = 0;
          } else {
            cout << -1;
            return 0;
          }
        } else
          assert(0);
      } else {
        if (arr[1].first == b) {
          if (arr[0].first + arr[1].second == a) {
            type = 2;
            xx = 0;
            yy = 1;
          } else {
            cout << -1;
            return 0;
          }
        } else if (arr[1].second == b) {
          if (arr[0].first + arr[1].first == a) {
            type = 2;
            xx = 0;
            yy = 0;
          } else {
            cout << -1;
            return 0;
          }
        } else
          assert(0);
      }
    } else {
      cout << -1;
      return 0;
    }
  } else {
    cout << -1;
    return 0;
  }
  if (type == 1) {
    cout << a << '\n';
    for (int i = 0; i < a - b; ++i) {
      for (int j = 0; j < a; ++j) {
        char c = 'A' + index - 1;
        cout << c;
      }
      cout << '\n';
    }
    int index1, index2, zz = 0;
    for (int i = 1; i <= 3; ++i) {
      if (index != i && zz == 0)
        index1 = i, zz++;
      else if (index != i && zz == 1)
        index2 = i, zz++;
    }
    int z1, z2;
    if (xx == 0)
      z1 = arr[0].first;
    else
      z1 = arr[0].second;
    for (int i = 0; i < z1; ++i) {
      for (int j = 0; j < a; ++j) {
        char c = 'A' - 1 + index1;
        cout << c;
      }
      cout << '\n';
    }
    if (yy == 0)
      z1 = arr[1].first;
    else
      z1 = arr[1].second;
    for (int i = 0; i < z1; ++i) {
      for (int j = 0; j < a; ++j) {
        char c = 'A' - 1 + index2;
        cout << c;
      }
      cout << '\n';
    }
  } else if (type == 2) {
    cout << a << '\n';
    for (int i = 0; i < a - b; ++i) {
      for (int j = 0; j < a; ++j) {
        char c = 'A' + index - 1;
        cout << c;
      }
      cout << '\n';
    }
    int index1, index2, zz = 0;
    for (int i = 1; i <= 3; ++i) {
      if (index != i && zz == 0)
        index1 = i, zz++;
      else if (index != i && zz == 1)
        index2 = i, zz++;
    }
    int z1, z2;
    if (xx == 0)
      z1 = arr[0].first;
    else
      z1 = arr[0].second;
    if (yy == 0)
      z2 = arr[1].first;
    else
      z2 = arr[1].second;
    for (int i = 0; i < b; ++i) {
      for (int j = 0; j < z1; ++j) {
        char c = 'A' - 1 + index1;
        cout << c;
      }
      for (int j = 0; j < z2; ++j) {
        char c = 'A' - 1 + index2;
        cout << c;
      }
      cout << '\n';
    }
  } else
    cout << -1;
}
