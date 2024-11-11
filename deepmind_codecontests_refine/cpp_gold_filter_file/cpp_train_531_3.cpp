#include <bits/stdc++.h>
using namespace std;
int c = 0;
int dist(int x, int yl, int yr) {
  int dist = (yr - yl + 1) * abs(x - c);
  for (int y = yl; y <= yr; y++) {
    dist += abs(y - c);
  }
  return dist;
}
int main() {
  int n, k;
  cin >> n >> k;
  c = (k + 1) / 2;
  vector<int> requests;
  for (int i = 0; i < n; i++) {
    int r;
    cin >> r;
    requests.push_back(r);
  }
  vector<int> rows;
  rows.push_back((k + 1) / 2);
  for (int i = 1; i < (k + 1) / 2; i++) {
    rows.push_back((k + 1) / 2 - i);
    rows.push_back((k + 1) / 2 + i);
  }
  unordered_map<int, vector<int>> seats;
  for (int row : rows) {
    seats[row].push_back(k);
  }
  for (int req : requests) {
    if (req > k) {
      cout << -1 << endl;
      continue;
    }
    int min_dist = -1, x = 0, yl = 0, yr = 0;
    vector<int> seat;
    for (int row : rows) {
      if (seats[row].size() == 1) {
        int _yl = (k - req) / 2 + 1;
        int _yr = _yl + req - 1;
        int d = dist(row, _yl, _yr);
        if (min_dist == -1 || min_dist > d || (min_dist == d && row < x)) {
          x = row;
          yl = _yl;
          yr = _yr;
          min_dist = d;
          seat.clear();
          seat.push_back(yl - 1);
          seat.push_back(k - yr);
        }
      } else {
        if (seats[row][0] >= req) {
          int _yr = seats[row][0];
          int _yl = _yr - req + 1;
          int d = dist(row, _yl, _yr);
          if (min_dist == -1 || min_dist > d || (min_dist == d && row < x)) {
            x = row;
            yl = _yl;
            yr = _yr;
            min_dist = d;
            seat = seats[row];
            seat[0] -= req;
          }
        }
        if (seats[row][1] >= req) {
          int _yl = k - seats[row][1] + 1;
          int _yr = _yl + req - 1;
          int d = dist(row, _yl, _yr);
          if (min_dist == -1 || min_dist > d || (min_dist == d && row < x)) {
            x = row;
            yl = _yl;
            yr = _yr;
            min_dist = d;
            seat = seats[row];
            seat[1] -= req;
          }
        }
      }
    }
    if (min_dist == -1) {
      cout << -1 << endl;
    } else {
      cout << x << " " << yl << " " << yr << endl;
      seats[x] = seat;
    }
  }
  return 0;
}
