#include <bits/stdc++.h>
using namespace std;
int N;
inline bool int_less_than(int a, int b) { return a < b; }
bool interval_less_than(const pair<pair<int, int>, int> &lhs,
                        const pair<pair<int, int>, int> &rhs) {
  if (lhs.first.second == rhs.first.second) {
    return int_less_than(lhs.first.first, rhs.first.first);
  }
  return int_less_than(lhs.first.second, rhs.first.second);
}
bool overlap(const pair<int, int> &lhs, const pair<int, int> &rhs) {
  return max(lhs.first, rhs.first) <= min(lhs.second, rhs.second);
}
vector<int> solve(vector<pair<pair<int, int>, int> > &interval, int K) {
  int current = 0;
  vector<int> order, max_pos(N), pos(N);
  int subsum[N];
  for (int i = 0; i < N; i++) {
    max_pos[i] = N - 1;
    pos[i] = -1;
  }
  for (int count = 0; count < N; count++) {
    pos[current] = count;
    memset(subsum, 0, sizeof(subsum));
    for (int i = 0; i < N; i++) {
      if (pos[i] < 0) {
        if (overlap(interval[i].first, interval[current].first)) {
          max_pos[i] = min(max_pos[i], pos[current] + K);
        }
        ++subsum[max_pos[i]];
      }
    }
    for (int jj = count + 1; jj < N; jj++) subsum[jj] += subsum[jj - 1];
    int j = K - count + 1, min_j = -1;
    if (j < 1) j = 1;
    while (count + j < N) {
      if (subsum[count + j] > j) {
        return order;
      }
      if (subsum[count + j] == j && min_j < 0) {
        min_j = j;
      }
      ++j;
    }
    current = -1;
    for (int i = 0; i < N; i++) {
      if (pos[i] < 0 && max_pos[i] <= count + min_j) {
        current = i;
        break;
      }
    }
  }
  order.resize(N);
  for (int i = 0; i < N; i++) {
    order[pos[i]] = interval[i].second;
  }
  return order;
}
int main(const int argc, const char **argv) {
  (cin >> N);
  {
    vector<pair<pair<int, int>, int> > interval(N);
    for (int i = 0; i < N; i++) {
      cin >> interval[i].first.first >> interval[i].first.second;
      interval[i].second = i + 1;
    }
    sort(interval.begin(), interval.end(), interval_less_than);
    int st = 1, ed = N - 1, mid;
    vector<int> result;
    while (st <= ed) {
      int mid = (st + ed) / 2;
      vector<int> order = solve(interval, mid);
      if (order.size() > 0) {
        result = order;
        ed = mid - 1;
      } else {
        st = mid + 1;
      }
    }
    for (int i = 0; i < N; i++) cout << result[i] << " ";
    cout << endl;
  }
  return 0;
}
