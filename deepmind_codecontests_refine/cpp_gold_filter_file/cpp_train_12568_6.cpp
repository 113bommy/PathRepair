#include <bits/stdc++.h>
using namespace std;
array<int, 2> to_coord(int pos, int n) {
  if (pos < n) {
    return {1, pos};
  } else {
    return {2, n - pos % n - 1};
  }
}
array<int, 3> next_coord(vector<int>& cars, int pos, int n) {
  int next_pos = (pos + 1) % (2 * n);
  cars[next_pos] = cars[pos];
  cars[pos] = 0;
  auto coord = to_coord(next_pos, n);
  return {cars[next_pos], coord[0] + 1, coord[1] + 1};
}
array<int, 3> place(vector<int>& cars, int pos, int n) {
  auto coord = to_coord(pos, n);
  coord[0] = coord[0] == 1 ? 1 : 4;
  int cp = cars[pos];
  cars[pos] = 0;
  return {cp, coord[0], coord[1] + 1};
}
int main() {
  std::ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  int tn = 2 * n;
  vector<int> places(tn), cars(tn);
  for (int i = 0; i < n; ++i) {
    cin >> places[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> cars[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> cars[tn - i - 1];
  }
  for (int i = 0; i < n; ++i) {
    cin >> places[tn - i - 1];
  }
  vector<array<int, 3>> result;
  int empty = -1;
  if (k == tn) {
    for (int i = 0; i < tn; ++i) {
      if (places[i] == cars[i]) {
        result.push_back(place(cars, i, n));
        empty = i;
        break;
      }
    }
    if (empty == -1) {
      cout << -1;
      return 0;
    }
  } else {
    for (int i = 0; i < tn; ++i) {
      if (cars[i] == 0) {
        empty = i;
        break;
      }
    }
  }
  for (int i = 0; i < tn; ++i) {
    for (int j = 0; j < tn; ++j) {
      int pos = (empty + i - 1 - j + tn) % tn;
      if (cars[pos] != 0) {
        if (cars[pos] == places[pos]) {
          result.push_back(place(cars, pos, n));
        } else {
          result.push_back(next_coord(cars, pos, n));
        }
      }
    }
  }
  cout << result.size() << endl;
  for (int i = 0; i < result.size(); ++i) {
    for (int j = 0; j < 3; ++j) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
