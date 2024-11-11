#include <bits/stdc++.h>
using namespace std;
vector<int> seat;
int getMax(vector<int> &seats, int people) {
  int ans = 0;
  for (int i = 1; i <= people; i++) {
    int cur_max = 0;
    int cur_ind = 0;
    for (int j = 0; j < seats.size(); j++) {
      if (seats[j] != 0 && cur_max < seats[j]) {
        cur_max = seats[j];
        cur_ind = j;
      }
    }
    ans += seats[cur_ind];
    seats[cur_ind]--;
  }
  return ans;
}
int getMin(vector<int> &seats, int people) {
  int ans = 0;
  for (int i = 1; i <= people; i++) {
    int cur_min = INT_MAX;
    int cur_ind = 0;
    for (int j = 0; j < seats.size(); j++) {
      if (seats[j] != 0 && seats[j] < cur_min) {
        cur_min = seats[j];
        cur_ind = j;
      }
    }
    ans += seats[cur_ind];
    seats[cur_ind]--;
  }
  return ans;
}
int main() {
  int n, m, v;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> v;
    seat.push_back(v);
  }
  vector<int> tmp = seat;
  cout << getMin(tmp, n) << " " << getMax(seat, n) << endl;
}
