#include <bits/stdc++.h>
using namespace std;
const double pi = 4 * atan(1.0);
constexpr long long mod = static_cast<long long>(1e9 + 7);
using cEdges = vector<vector<int>>;
int BinarySearch(int min, int max, function<bool(int, int&, int&)> func) {
  while (1) {
    int mid = (max - min) / 2 + min;
    if (mid == min) {
      bool ans = func(mid, min, max);
      if (!ans) ++mid;
      return mid;
    }
    func(mid, min, max);
  }
}
int query(int x1, int y1, int x2, int y2) {
  cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
  fflush(stdout);
  int ans;
  cin >> ans;
  return ans;
}
int main() {
  int n;
  cin >> n;
  int Top1, Bot1, Top2, Bot2;
  int Right1, Left1, Right2, Left2;
  Bot1 = BinarySearch(1, n + 1, [=](int mid, int& min, int& max) -> bool {
    int x1, y1, x2, y2;
    y1 = mid, y2 = n;
    x1 = 1, x2 = n;
    int ans = query(x1, y1, x2, y2);
    if (ans > 0) {
      min = mid;
      return true;
    } else {
      max = mid;
      return false;
    }
  });
  Top1 = BinarySearch(Bot1, n + 1, [=](int mid, int& min, int& max) -> bool {
    int x1, y1, x2, y2;
    y1 = Bot1, y2 = mid;
    x1 = 1, x2 = n;
    int ans = query(x1, y1, x2, y2);
    if (ans > 0) {
      max = mid;
      return true;
    } else {
      min = mid;
      return false;
    }
  });
  Bot2 = BinarySearch(1, Bot1, [=](int mid, int& min, int& max) -> bool {
    int x1, y1, x2, y2;
    y1 = mid, y2 = n;
    x1 = 1, x2 = n;
    int ans = query(x1, y1, x2, y2);
    if (ans > 1) {
      min = mid;
      return true;
    } else {
      max = mid;
      return false;
    }
  });
  int x1, y1, x2, y2;
  int ans;
  if (Bot2 < n) {
    x1 = 1, x2 = n;
    y1 = Bot2 + 1, y2 = n;
    ans = query(x1, y1, x2, y2);
    if (ans == 2) ++Bot2;
  }
  x1, y1, x2, y2;
  y1 = Bot2, y2 = Top1;
  x1 = 1, x2 = n;
  ans = query(x1, y1, x2, y2);
  if (ans == 2) {
    Top2 = BinarySearch(Bot2, n + 1, [=](int mid, int& min, int& max) -> bool {
      int x1, y1, x2, y2;
      y1 = Bot2, y2 = mid;
      x1 = 1, x2 = n;
      int ans = query(x1, y1, x2, y2);
      if (ans > 0) {
        max = mid;
        return true;
      } else {
        min = mid;
        return false;
      }
    });
  } else {
    Top2 =
        BinarySearch(Top1 + 1, n + 1, [=](int mid, int& min, int& max) -> bool {
          int x1, y1, x2, y2;
          y1 = Bot2, y2 = mid;
          x1 = 1, x2 = n;
          int ans = query(x1, y1, x2, y2);
          if (ans > 1) {
            max = mid;
            return true;
          } else {
            min = mid;
            return false;
          }
        });
  }
  Left1 = BinarySearch(1, n + 1, [=](int mid, int& min, int& max) -> bool {
    int x1, y1, x2, y2;
    y1 = 1, y2 = n;
    x1 = mid, x2 = n;
    int ans = query(x1, y1, x2, y2);
    if (ans > 0) {
      min = mid;
      return true;
    } else {
      max = mid;
      return false;
    }
  });
  Right1 = BinarySearch(Left1, n + 1, [=](int mid, int& min, int& max) -> bool {
    int x1, y1, x2, y2;
    y1 = 1, y2 = n;
    x1 = Left1, x2 = mid;
    int ans = query(x1, y1, x2, y2);
    if (ans > 0) {
      max = mid;
      return true;
    } else {
      min = mid;
      return false;
    }
  });
  Left2 = BinarySearch(1, Left1, [=](int mid, int& min, int& max) -> bool {
    int x1, y1, x2, y2;
    y1 = 1, y2 = n;
    x1 = mid, x2 = n;
    int ans = query(x1, y1, x2, y2);
    if (ans > 1) {
      min = mid;
      return true;
    } else {
      max = mid;
      return false;
    }
  });
  if (Left2 < n) {
    x1 = Left2 + 1, x2 = n;
    y1 = 1, y2 = n;
    ans = query(x1, y1, x2, y2);
    if (ans == 2) ++Left2;
  }
  x1 = Left2, x2 = Right1;
  y1 = 1, y2 = n;
  ans = query(x1, y1, x2, y2);
  if (ans == 2) {
    Right2 =
        BinarySearch(Left2, n + 1, [=](int mid, int& min, int& max) -> bool {
          int x1, y1, x2, y2;
          y1 = 1, y2 = n;
          x1 = Left2, x2 = mid;
          int ans = query(x1, y1, x2, y2);
          if (ans > 0) {
            max = mid;
            return true;
          } else {
            min = mid;
            return false;
          }
        });
  } else {
    Right2 = BinarySearch(Right1 + 1, n + 1,
                          [=](int mid, int& min, int& max) -> bool {
                            int x1, y1, x2, y2;
                            y1 = 1, y2 = n;
                            x1 = Left2, x2 = mid;
                            int ans = query(x1, y1, x2, y2);
                            if (ans > 1) {
                              max = mid;
                              return true;
                            } else {
                              min = mid;
                              return false;
                            }
                          });
  }
  x1 = Left1, x2 = Right1;
  y1 = Bot1, y2 = Top1;
  ans = query(x1, y1, x2, y2);
  if (ans > 0) {
    cout << "!" << Left1 << " " << Bot1 << " " << Right1 << " " << Top1 << " "
         << Left2 << " " << Bot2 << " " << Right2 << " " << Top2;
    cout << endl;
    fflush(stdout);
  } else {
    cout << "!" << Left2 << " " << Bot1 << " " << Right2 << " " << Top1 << " "
         << Left1 << " " << Bot2 << " " << Right1 << " " << Top2;
    cout << endl;
    fflush(stdout);
  }
  return 0;
}
